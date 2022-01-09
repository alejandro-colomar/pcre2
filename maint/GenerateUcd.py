#! /usr/bin/python

#                   PCRE2 UNICODE PROPERTY SUPPORT
#                   ------------------------------
#
# This script generates the pcre2_ucd.c file from Unicode data files. This is
# the compressed Unicode property data used by PCRE2. The script was created in
# December 2021 as part of the Unicode data generation refactoring. It is
# basically a re-working of the MultiStage2.py script that was submitted to the
# PCRE project by Peter Kankowski in 2008 as part of a previous upgrading of
# Unicode property support. A number of extensions have since been added. The
# main difference in the 2021 upgrade (apart from comments and layout) is that
# the data tables (e.g. list of script names) are now held in a separate Python
# module that is shared with the other Generate scripts.
#
# This script must be run in the "maint" directory. It requires eight Unicode
# data tables: DerivedBidiClass.txt, DerivedGeneralCategory.txt,
# GraphemeBreakProperty.txt, PropList.txt, Scripts.txt, ScriptExtensions.txt,
# CaseFolding.txt, and emoji-data.txt. These must be in the Unicode.tables
# subdirectory.
#
# DerivedBidiClass.txt and DerivedGeneralCategory.txt are in the "extracted"
# subdirectory of the Unicode database (UCD) on the Unicode web site;
# GraphemeBreakProperty.txt is in the "auxiliary" subdirectory. PropList.txt,
# Scripts.txt, ScriptExtensions.txt, and CaseFolding.txt are directly in the
# UCD directory.
#
# The emoji-data.txt file is found in the "emoji" subdirectory even though it
# is technically part of a different (but coordinated) standard as shown
# in files associated with Unicode Technical Standard #51 ("Unicode Emoji"),
# for example:
#
# http://unicode.org/Public/emoji/13.0/ReadMe.txt
#
# -----------------------------------------------------------------------------
# Minor modifications made to the original script:
#  Added #! line at start
#  Removed tabs
#  Made it work with Python 2.4 by rewriting two statements that needed 2.5
#  Consequent code tidy
#  Adjusted data file names to take from the Unicode.tables directory
#  Adjusted global table names by prefixing _pcre_.
#  Commented out stuff relating to the casefolding table, which isn't used;
#    removed completely in 2012.
#  Corrected size calculation
#  Add #ifndef SUPPORT_UCP to use dummy tables when no UCP support is needed.
#  Update for PCRE2: name changes, and SUPPORT_UCP is abolished.
#
# Major modifications made to the original script:
#  Added code to add a grapheme break property field to records.
#
#  Added code to search for sets of more than two characters that must match
#  each other caselessly. A new table is output containing these sets, and
#  offsets into the table are added to the main output records. This new
#  code scans CaseFolding.txt instead of UnicodeData.txt, which is no longer
#  used.
#
#  Update for Python3:
#    . Processed with 2to3, but that didn't fix everything
#    . Changed string.strip to str.strip
#    . Added encoding='utf-8' to the open() call
#    . Inserted 'int' before blocksize/ELEMS_PER_LINE because an int is
#        required and the result of the division is a float
#
#  Added code to scan the emoji-data.txt file to find the Extended Pictographic
#  property, which is used by PCRE2 as a grapheme breaking property. This was
#  done when updating to Unicode 11.0.0 (July 2018).
#
#  Added code to add a Script Extensions field to records. This has increased
#  their size from 8 to 12 bytes, only 10 of which are currently used.
#
#  Added code to add a bidi class field to records by scanning the
#  DerivedBidiClass.txt and PropList.txt files. This uses one of the two spare
#  bytes, so now 11 out of 12 are in use.
#
# 01-March-2010:     Updated list of scripts for Unicode 5.2.0
# 30-April-2011:     Updated list of scripts for Unicode 6.0.0
#     July-2012:     Updated list of scripts for Unicode 6.1.0
# 20-August-2012:    Added scan of GraphemeBreakProperty.txt and added a new
#                      field in the record to hold the value. Luckily, the
#                      structure had a hole in it, so the resulting table is
#                      not much bigger than before.
# 18-September-2012: Added code for multiple caseless sets. This uses the
#                      final hole in the structure.
# 30-September-2012: Added RegionalIndicator break property from Unicode 6.2.0
# 13-May-2014:       Updated for PCRE2
# 03-June-2014:      Updated for Python 3
# 20-June-2014:      Updated for Unicode 7.0.0
# 12-August-2014:    Updated to put Unicode version into the file
# 19-June-2015:      Updated for Unicode 8.0.0
# 02-July-2017:      Updated for Unicode 10.0.0
# 03-July-2018:      Updated for Unicode 11.0.0
# 07-July-2018:      Added code to scan emoji-data.txt for the Extended
#                      Pictographic property.
# 01-October-2018:   Added the 'Unknown' script name
# 03-October-2018:   Added new field for Script Extensions
# 27-July-2019:      Updated for Unicode 12.1.0
# 10-March-2020:     Updated for Unicode 13.0.0
# PCRE2-10.39:       Updated for Unicode 14.0.0
# 05-December-2021:  Added code to scan DerivedBidiClass.txt for bidi class,
#                      and also PropList.txt for the Bidi_Control property
# 19-December-2021:  Reworked script extensions lists to be bit maps instead
#                      of zero-terminated lists of script numbers.
# ----------------------------------------------------------------------------
#
# Changes to the refactored script:
#
# 26-December-2021:  Refactoring completed
#
# ----------------------------------------------------------------------------
#
#
# The main tables generated by this script are used by macros defined in
# pcre2_internal.h. They look up Unicode character properties using short
# sequences of code that contains no branches, which makes for greater speed.
#
# Conceptually, there is a table of records (of type ucd_record), one for each
# Unicode character. Each record contains the script number, script extension
# value, character type, grapheme break type, offset to caseless matching set,
# offset to the character's other case, and the bidi class/control.
#
# A real table covering all Unicode characters would be far too big. It can be
# efficiently compressed by observing that many characters have the same
# record, and many blocks of characters (taking 128 characters in a block) have
# the same set of records as other blocks. This leads to a 2-stage lookup
# process.
#
# This script constructs six tables. The ucd_caseless_sets table contains
# lists of characters that all match each other caselessly. Each list is
# in order, and is terminated by NOTACHAR (0xffffffff), which is larger than
# any valid character. The first list is empty; this is used for characters
# that are not part of any list.
#
# The ucd_digit_sets table contains the code points of the '9' characters in
# each set of 10 decimal digits in Unicode. This is used to ensure that digits
# in script runs all come from the same set. The first element in the vector
# contains the number of subsequent elements, which are in ascending order.
#
# The lists of scripts in script_names and script_abbrevs are partitioned into
# two groups. Scripts that appear in at least one character's script extension
# list come first, follwed by "Unknown" and then all the rest. This sorting is
# done certain automatically in the GenerateCommon.py script. A script's number
# is its index in these lists.
#
# The ucd_script_sets vector contains bitmaps that represent lists of scripts
# for Script Extensions properties. Each bitmap consists of a fixed number of
# unsigned 32-bit numbers, enough to allocate a bit for every script that is
# used in any character's extension list, that is, enough for every script
# whose number is less than ucp_Unknown. A character's script extension value
# in its ucd record is an offset into the ucd_script_sets vector. The first
# bitmap has no bits set; characters that have no script extensions have zero
# as their script extensions value so that they use this map.
#
# The ucd_records table contains one instance of every unique record that is
# required. The ucd_stage1 table is indexed by a character's block number,
# which is the character's code point divided by 128, since 128 is the size
# of each block. The result of a lookup in ucd_stage1 a "virtual" block number.
#
# The ucd_stage2 table is a table of "virtual" blocks; each block is indexed by
# the offset of a character within its own block, and the result is the index
# number of the required record in the ucd_records vector.
#
# The following examples are correct for the Unicode 14.0.0 database. Future
# updates may make change the actual lookup values.
#
# Example: lowercase "a" (U+0061) is in block 0
#          lookup 0 in stage1 table yields 0
#          lookup 97 (0x61) in the first table in stage2 yields 23
#          record 23 is { 20, 5, 12, 0, -32, 0, 9, 0 }
#            20 = ucp_Latin   => Latin script
#             5 = ucp_Ll      => Lower case letter
#            12 = ucp_gbOther => Grapheme break property "Other"
#             0               => Not part of a caseless set
#           -32 (-0x20)       => Other case is U+0041
#             0               => No special Script Extension property
#             9 = ucp_bidiL   => Bidi class left-to-right
#             0               => Dummy value, unused at present
#
# Almost all lowercase latin characters resolve to the same record. One or two
# are different because they are part of a multi-character caseless set (for
# example, k, K and the Kelvin symbol are such a set).
#
# Example: hiragana letter A (U+3042) is in block 96 (0x60)
#          lookup 96 in stage1 table yields 91
#          lookup 66 (0x42) in table 91 in stage2 yields 614
#          record 614 is { 17, 7, 12, 0, 0, 0, 9, 0 }
#            17 = ucp_Hiragana => Hiragana script
#             7 = ucp_Lo       => Other letter
#            12 = ucp_gbOther  => Grapheme break property "Other"
#             0                => Not part of a caseless set
#             0                => No other case
#             0                => No special Script Extension property
#             9 = ucp_bidiL    => Bidi class left-to-right
#             0                => Dummy value, unused at present
#
# Example: vedic tone karshana (U+1CD0) is in block 57 (0x39)
#          lookup 57 in stage1 table yields 55
#          lookup 80 (0x50) in table 55 in stage2 yields 486
#          record 485 is { 78, 12, 3, 0, 0, 138, 13, 0 }
#            78 = ucp_Inherited => Script inherited from predecessor
#            12 = ucp_Mn        => Non-spacing mark
#             3 = ucp_gbExtend  => Grapheme break property "Extend"
#             0                 => Not part of a caseless set
#             0                 => No other case
#           138                 => Script Extension list offset = 138
#            13 = ucp_bidiNSM   => Bidi class non-spacing mark
#             0                 => Dummy value, unused at present
#
# At offset 138 in the ucd_script_sets vector we find a bitmap with bits 1, 8,
# 18, and 47 set. This means that this character is expected to be used with
# any of those scripts, which are Bengali, Devanagari, Kannada, and Grantha.
#
#  Philip Hazel, last updated 31 December 2021.
##############################################################################


# Import standard modules

import re
import string
import sys

# Import common data lists and functions

from GenerateCommon import \
  bidi_classes, \
  bool_properties, \
  bool_propsfiles, \
  bool_props_list_item_size, \
  break_properties, \
  category_names, \
  general_category_names, \
  script_abbrevs, \
  script_list_item_size, \
  script_names, \
  open_output

# Some general parameters

MAX_UNICODE = 0x110000
NOTACHAR = 0xffffffff


# ---------------------------------------------------------------------------
#                         DEFINE FUNCTIONS
# ---------------------------------------------------------------------------


# Parse a line of Scripts.txt, GraphemeBreakProperty.txt, DerivedBidiClass.txt
# or DerivedGeneralCategory.txt

def make_get_names(enum):
  return lambda chardata: enum.index(chardata[1])


# Parse a line of CaseFolding.txt

def get_other_case(chardata):
  if chardata[1] == 'C' or chardata[1] == 'S':
    return int(chardata[2], 16) - int(chardata[0], 16)
  return 0


# Parse a line of ScriptExtensions.txt

def get_script_extension(chardata):
  global last_script_extension

  offset = len(script_lists) * script_list_item_size
  if last_script_extension == chardata[1]:
    return offset - script_list_item_size

  last_script_extension = chardata[1]
  script_lists.append(tuple(script_abbrevs.index(abbrev) for abbrev in last_script_extension.split(' ')))
  return offset


# Read a whole table in memory, setting/checking the Unicode version

def read_table(file_name, get_value, default_value):
  global unicode_version

  f = re.match(r'^[^/]+/([^.]+)\.txt$', file_name)
  file_base = f.group(1)
  version_pat = r"^# " + re.escape(file_base) + r"-(\d+\.\d+\.\d+)\.txt$"
  file = open(file_name, 'r', encoding='utf-8')
  f = re.match(version_pat, file.readline())
  version = f.group(1)
  if unicode_version == "":
    unicode_version = version
  elif unicode_version != version:
    print("WARNING: Unicode version differs in %s", file_name, file=sys.stderr)

  table = [default_value] * MAX_UNICODE
  for line in file:
    line = re.sub(r'#.*', '', line)
    chardata = list(map(str.strip, line.split(';')))
    if len(chardata) <= 1:
      continue
    value = get_value(chardata)
    m = re.match(r'([0-9a-fA-F]+)(\.\.([0-9a-fA-F]+))?$', chardata[0])
    char = int(m.group(1), 16)
    if m.group(3) is None:
      last = char
    else:
      last = int(m.group(3), 16)
    for i in range(char, last + 1):
      # It is important not to overwrite a previously set value because in the
      # CaseFolding file there are lines to be ignored (returning the default
      # value of 0) which often come after a line which has already set data.
      if table[i] == default_value:
        table[i] = value
  file.close()
  return table


# Get the smallest possible C language type for the values in a table

def get_type_size(table):
  type_size = [("uint8_t", 1), ("uint16_t", 2), ("uint32_t", 4),
    ("signed char", 1), ("int16_t", 2), ("int32_t", 4)]
  limits = [(0, 255), (0, 65535), (0, 4294967295), (-128, 127),
    (-32768, 32767), (-2147483648, 2147483647)]
  minval = min(table)
  maxval = max(table)
  for num, (minlimit, maxlimit) in enumerate(limits):
    if minlimit <= minval and maxval <= maxlimit:
      return type_size[num]
  raise OverflowError("Too large to fit into C types")


# Get the total size of a list of tables

def get_tables_size(*tables):
  total_size = 0
  for table in tables:
    type, size = get_type_size(table)
    total_size += size * len(table)
  return total_size


# Compress a table into the two stages

def compress_table(table, block_size):
  blocks = {} # Dictionary for finding identical blocks
  stage1 = [] # Stage 1 table contains block numbers (indices into stage 2 table)
  stage2 = [] # Stage 2 table contains the blocks with property values
  table = tuple(table)
  for i in range(0, len(table), block_size):
    block = table[i:i+block_size]
    start = blocks.get(block)
    if start is None:
      # Allocate a new block
      start = len(stage2) / block_size
      stage2 += block
      blocks[block] = start
    stage1.append(start)
  return stage1, stage2


# Output a table

def write_table(table, table_name, block_size = None):
  type, size = get_type_size(table)
  ELEMS_PER_LINE = 16

  s = "const %s %s[] = { /* %d bytes" % (type, table_name, size * len(table))
  if block_size:
    s += ", block = %d" % block_size
  f.write(s + " */\n")
  table = tuple(table)
  if block_size is None:
    fmt = "%3d," * ELEMS_PER_LINE + " /* U+%04X */\n"
    mult = MAX_UNICODE / len(table)
    for i in range(0, len(table), ELEMS_PER_LINE):
      f.write(fmt % (table[i:i+ELEMS_PER_LINE] + (int(i * mult),)))
  else:
    if block_size > ELEMS_PER_LINE:
      el = ELEMS_PER_LINE
    else:
      el = block_size
    fmt = "%3d," * el + "\n"
    if block_size > ELEMS_PER_LINE:
      fmt = fmt * int(block_size / ELEMS_PER_LINE)
    for i in range(0, len(table), block_size):
      f.write(("\n/* block %d */\n" + fmt) % ((i / block_size,) + table[i:i+block_size]))
  f.write("};\n\n")


# Extract the unique combinations of properties into records

def combine_tables(*tables):
  records = {}
  index = []
  for t in zip(*tables):
    i = records.get(t)
    if i is None:
      i = records[t] = len(records)
    index.append(i)
  return index, records


# Create a record struct

def get_record_size_struct(records):
  size = 0
  structure = 'typedef struct {\n'
  for i in range(len(records[0])):
    record_slice = [record[i] for record in records]
    slice_type, slice_size = get_type_size(record_slice)
    # add padding: round up to the nearest power of slice_size
    size = (size + slice_size - 1) & -slice_size
    size += slice_size
    structure += '%s property_%d;\n' % (slice_type, i)

  # round up to the first item of the next structure in array
  record_slice = [record[0] for record in records]
  slice_type, slice_size = get_type_size(record_slice)
  size = (size + slice_size - 1) & -slice_size

  structure += '} ucd_record;\n*/\n'
  return size, structure


# Write records

def write_records(records, record_size):
  f.write('const ucd_record PRIV(ucd_records)[] = { ' + \
    '/* %d bytes, record size %d */\n' % (len(records) * record_size, record_size))
  records = list(zip(list(records.keys()), list(records.values())))
  records.sort(key = lambda x: x[1])
  for i, record in enumerate(records):
    f.write(('  {' + '%6d, ' * len(record[0]) + '}, /* %3d */\n') % (record[0] + (i,)))
  f.write('};\n\n')


# Write a bit set

def write_bitsets(list, item_size):
  for d in list:
    bitwords = [0] * item_size
    for idx in d:
      bitwords[idx // 32] |= 1 << (idx & 31)
    s = " "
    for x in bitwords:
      f.write("%s" % s)
      s = ", "
      f.write("0x%08xu" % x)
    f.write(",\n")
  f.write("};\n\n")


# ---------------------------------------------------------------------------
# This bit of code must have been useful when the original script was being
# developed. Retain it just in case it is ever needed again.

# def test_record_size():
#   tests = [ \
#     ( [(3,), (6,), (6,), (1,)], 1 ), \
#     ( [(300,), (600,), (600,), (100,)], 2 ), \
#     ( [(25, 3), (6, 6), (34, 6), (68, 1)], 2 ), \
#     ( [(300, 3), (6, 6), (340, 6), (690, 1)], 4 ), \
#     ( [(3, 300), (6, 6), (6, 340), (1, 690)], 4 ), \
#     ( [(300, 300), (6, 6), (6, 340), (1, 690)], 4 ), \
#     ( [(3, 100000), (6, 6), (6, 123456), (1, 690)], 8 ), \
#     ( [(100000, 300), (6, 6), (123456, 6), (1, 690)], 8 ), \
#   ]
#   for test in tests:
#     size, struct = get_record_size_struct(test[0])
#     assert(size == test[1])
# test_record_size()
# ---------------------------------------------------------------------------



# ---------------------------------------------------------------------------
#                       MAIN CODE FOR CREATING TABLES
# ---------------------------------------------------------------------------

unicode_version = ""

# Some of the tables imported from GenerateCommon.py have alternate comment
# strings for use by GenerateUcpHeader. The comments are now wanted here, so
# remove them.

bidi_classes = bidi_classes[::2]
break_properties = break_properties[::2]
category_names = category_names[::2]

# Create the various tables from Unicode data files

script = read_table('Unicode.tables/Scripts.txt', make_get_names(script_names), script_names.index('Unknown'))
category = read_table('Unicode.tables/DerivedGeneralCategory.txt', make_get_names(category_names), category_names.index('Cn'))
break_props = read_table('Unicode.tables/GraphemeBreakProperty.txt', make_get_names(break_properties), break_properties.index('Other'))
other_case = read_table('Unicode.tables/CaseFolding.txt', get_other_case, 0)
bidi_class = read_table('Unicode.tables/DerivedBidiClass.txt', make_get_names(bidi_classes), bidi_classes.index('L'))

# The grapheme breaking rules were changed for Unicode 11.0.0 (June 2018). Now
# we need to find the Extended_Pictographic property for emoji characters. This
# can be set as an additional grapheme break property, because the default for
# all the emojis is "other". We scan the emoji-data.txt file and modify the
# break-props table.

file = open('Unicode.tables/emoji-data.txt', 'r', encoding='utf-8')
for line in file:
  line = re.sub(r'#.*', '', line)
  chardata = list(map(str.strip, line.split(';')))
  if len(chardata) <= 1:
    continue
  if chardata[1] != "Extended_Pictographic":
    continue
  m = re.match(r'([0-9a-fA-F]+)(\.\.([0-9a-fA-F]+))?$', chardata[0])
  char = int(m.group(1), 16)
  if m.group(3) is None:
    last = char
  else:
    last = int(m.group(3), 16)
  for i in range(char, last + 1):
    if break_props[i] != break_properties.index('Other'):
      print("WARNING: Emoji 0x%x has break property %s, not 'Other'",
        i, break_properties[break_props[i]], file=sys.stderr)
    break_props[i] = break_properties.index('Extended_Pictographic')
file.close()

# The Script Extensions property default value is the Script value. Parse the
# file, setting 'Unknown' as the default (this will never be a Script Extension
# value), then scan it and fill in the default from Scripts. Code added by PH
# in October 2018. Positive values are used for just a single script for a
# code point. Negative values are negated offsets in a list of bitsets of
# multiple scripts. Initialize this list with a single entry, as the zeroth
# element is never used.

script_lists = [[]]

last_script_extension = ""
scriptx = read_table('Unicode.tables/ScriptExtensions.txt', get_script_extension, 0)

# Find the Boolean properties of each character. This next bit of magic creates
# a list of empty lists. Just using [[]] * MAX_UNICODE gives a list of
# references to the *same* list, which is not what we want.

bprops = [[] for _ in range(MAX_UNICODE)]

# Collect the properties from the various files

for filename in bool_propsfiles:
  try:
    file = open('Unicode.tables/' + filename, 'r')
  except IOError:
    print(f"** Couldn't open {'Unicode.tables/' + filename}\n")
    sys.exit(1)

  for line in file:
    line = re.sub(r'#.*', '', line)
    data = list(map(str.strip, line.split(';')))
    if len(data) <= 1:
      continue

    try:
      ix = bool_properties.index(data[1])
    except ValueError:
      continue

    m = re.match(r'([0-9a-fA-F]+)(\.\.([0-9a-fA-F]+))?$', data[0])
    char = int(m.group(1), 16)
    if m.group(3) is None:
      last = char
    else:
      last = int(m.group(3), 16)

    for i in range(char, last + 1):
      bprops[i].append(ix)

  file.close()

# The ASCII property isn't listed in any files, but it is easy enough to add
# it manually.

ix = bool_properties.index("ASCII")
for i in range(128):
  bprops[i].append(ix)

# The Bidi_Mirrored property isn't listed in any property files. We have to
# deduce it from the file that lists the mirrored characters.

ix = bool_properties.index("Bidi_Mirrored")

try:
  file = open('Unicode.tables/BidiMirroring.txt', 'r')
except IOError:
  print(f"** Couldn't open {'Unicode.tables/BidiMirroring.txt'}\n")
  sys.exit(1)

for line in file:
  line = re.sub(r'#.*', '', line)
  data = list(map(str.strip, line.split(';')))
  if len(data) <= 1:
    continue
  c = int(data[0], 16)
  bprops[c].append(ix)

file.close()


# Scan each character's boolean property list and created a list of unique
# lists, at the same time, setting the index in that list for each property in
# the bool_props vector.

bool_props = [0] * MAX_UNICODE
bool_props_lists = [[]]

for c in range(MAX_UNICODE):
  s = set(bprops[c])
  for i in range(len(bool_props_lists)):
    if s == set(bool_props_lists[i]):
      break;
  else:
    bool_props_lists.append(bprops[c])
    i += 1

  bool_props[c] = i


# With the addition of the Script Extensions field, we needed some padding to
# get the Unicode records up to 12 bytes (multiple of 4). Originally this was a
# 16-bit field and padding_dummy[0] was set to 256 to ensure this, but 8 bits
# are now used, so zero will do.

padding_dummy = [0] * MAX_UNICODE
padding_dummy[0] = 0

# This block of code was added by PH in September 2012. It scans the other_case
# table to find sets of more than two characters that must all match each other
# caselessly. Later in this script a table of these sets is written out.
# However, we have to do this work here in order to compute the offsets in the
# table that are inserted into the main table.

# The CaseFolding.txt file lists pairs, but the common logic for reading data
# sets only one value, so first we go through the table and set "return"
# offsets for those that are not already set.

for c in range(MAX_UNICODE):
  if other_case[c] != 0 and other_case[c + other_case[c]] == 0:
    other_case[c + other_case[c]] = -other_case[c]

# Now scan again and create equivalence sets.

caseless_sets = []

for c in range(MAX_UNICODE):
  o = c + other_case[c]

  # Trigger when this character's other case does not point back here. We
  # now have three characters that are case-equivalent.

  if other_case[o] != -other_case[c]:
    t = o + other_case[o]

    # Scan the existing sets to see if any of the three characters are already
    # part of a set. If so, unite the existing set with the new set.

    appended = 0
    for s in caseless_sets:
      found = 0
      for x in s:
        if x == c or x == o or x == t:
          found = 1

      # Add new characters to an existing set

      if found:
        found = 0
        for y in [c, o, t]:
          for x in s:
            if x == y:
              found = 1
          if not found:
            s.append(y)
        appended = 1

    # If we have not added to an existing set, create a new one.

    if not appended:
      caseless_sets.append([c, o, t])

# End of loop looking for caseless sets.

# Now scan the sets and set appropriate offsets for the characters.

caseless_offsets = [0] * MAX_UNICODE

offset = 1;
for s in caseless_sets:
  for x in s:
    caseless_offsets[x] = offset
  offset += len(s) + 1

# End of block of code for creating offsets for caseless matching sets.


# Combine all the tables

table, records = combine_tables(script, category, break_props,
  caseless_offsets, other_case, scriptx, bidi_class, bool_props, padding_dummy)

# Find the record size and create a string definition of the structure for
# outputting as a comment.

record_size, record_struct = get_record_size_struct(list(records.keys()))

# Find the optimum block size for the two-stage table

min_size = sys.maxsize
for block_size in [2 ** i for i in range(5,10)]:
  size = len(records) * record_size
  stage1, stage2 = compress_table(table, block_size)
  size += get_tables_size(stage1, stage2)
  #print "/* block size %5d  => %5d bytes */" % (block_size, size)
  if size < min_size:
    min_size = size
    min_stage1, min_stage2 = stage1, stage2
    min_block_size = block_size


# ---------------------------------------------------------------------------
#                   MAIN CODE FOR WRITING THE OUTPUT FILE
# ---------------------------------------------------------------------------

# Open the output file (no return on failure). This call also writes standard
# header boilerplate.

f = open_output("pcre2_ucd.c")

# Output this file's heading text

f.write("""\
/* This file contains tables of Unicode properties that are extracted from
Unicode data files. See the comments at the start of maint/GenerateUcd.py for
details.

As well as being part of the PCRE2 library, this file is #included by the
pcre2test program, which redefines the PRIV macro to change table names from
_pcre2_xxx to xxxx, thereby avoiding name clashes with the library. At present,
just one of these tables is actually needed. When compiling the library, some
headers are needed. */

#ifndef PCRE2_PCRE2TEST
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "pcre2_internal.h"
#endif /* PCRE2_PCRE2TEST */

/* The tables herein are needed only when UCP support is built, and in PCRE2
that happens automatically with UTF support. This module should not be
referenced otherwise, so it should not matter whether it is compiled or not.
However a comment was received about space saving - maybe the guy linked all
the modules rather than using a library - so we include a condition to cut out
the tables when not needed. But don't leave a totally empty module because some
compilers barf at that. Instead, just supply some small dummy tables. */

#ifndef SUPPORT_UNICODE
const ucd_record PRIV(ucd_records)[] = {{0,0,0,0,0,0,0,0 }};
const uint16_t PRIV(ucd_stage1)[] = {0};
const uint16_t PRIV(ucd_stage2)[] = {0};
const uint32_t PRIV(ucd_caseless_sets)[] = {0};
#else
\n""")

# --- Output some variable heading stuff ---

f.write("/* Total size: %d bytes, block size: %d. */\n\n" % (min_size, min_block_size))
f.write('const char *PRIV(unicode_version) = "{}";\n\n'.format(unicode_version))

f.write("""\
/* When recompiling tables with a new Unicode version, please check the types
in this structure definition with those in pcre2_internal.h (the actual field
names will be different).
\n""")

f.write(record_struct)

f.write("""
/* If the 32-bit library is run in non-32-bit mode, character values greater
than 0x10ffff may be encountered. For these we set up a special record. */

#if PCRE2_CODE_UNIT_WIDTH == 32
const ucd_record PRIV(dummy_ucd_record)[] = {{
  ucp_Unknown,    /* script */
  ucp_Cn,         /* type unassigned */
  ucp_gbOther,    /* grapheme break property */
  0,              /* case set */
  0,              /* other case */
  ucp_Unknown,    /* script extension */
  ucp_bidiL,      /* bidi class */
  0,              /* bool properties offset */ 
  0               /* dummy filler */
  }};
#endif
\n""")

# --- Output the table of caseless character sets ---

f.write("""\
/* This table contains lists of characters that are caseless sets of
more than one character. Each list is terminated by NOTACHAR. */

const uint32_t PRIV(ucd_caseless_sets)[] = {
  NOTACHAR,
""")

for s in caseless_sets:
  s = sorted(s)
  for x in s:
    f.write('  0x%04x,' % x)
  f.write('  NOTACHAR,\n')
f.write('};\n\n')

# --- Other tables are not needed by pcre2test ---

f.write("""\
/* When #included in pcre2test, we don't need the table of digit sets, nor the
the large main UCD tables. */

#ifndef PCRE2_PCRE2TEST
\n""")

# --- Read Scripts.txt again for the sets of 10 digits. ---

digitsets = []
file = open('Unicode.tables/Scripts.txt', 'r', encoding='utf-8')

for line in file:
  m = re.match(r'([0-9a-fA-F]+)\.\.([0-9a-fA-F]+)\s+;\s+\S+\s+#\s+Nd\s+', line)
  if m is None:
    continue
  first = int(m.group(1),16)
  last  = int(m.group(2),16)
  if ((last - first + 1) % 10) != 0:
    f.write("ERROR: %04x..%04x does not contain a multiple of 10 characters" % (first, last),
      file=sys.stderr)
  while first < last:
    digitsets.append(first + 9)
    first += 10
file.close()
digitsets.sort()

f.write("""\
/* This table lists the code points for the '9' characters in each set of
decimal digits. It is used to ensure that all the digits in a script run come
from the same set. */

const uint32_t PRIV(ucd_digit_sets)[] = {
""")

f.write("  %d,  /* Number of subsequent values */" % len(digitsets))
count = 8
for d in digitsets:
  if count == 8:
    f.write("\n ")
    count = 0
  f.write(" 0x%05x," % d)
  count += 1
f.write("\n};\n\n")

f.write("""\
/* This vector is a list of script bitsets for the Script Extension property. */

const uint32_t PRIV(ucd_script_sets)[] = {
""")
write_bitsets(script_lists, script_list_item_size)

f.write("""\
/* This vector is a list of bitsets for Boolean properties. */

const uint32_t PRIV(ucd_boolprop_sets)[] = {
""")
write_bitsets(bool_props_lists, bool_props_list_item_size)


# Output the main UCD tables.

f.write("""\
/* These are the main two-stage UCD tables. The fields in each record are:
script (8 bits), character type (8 bits), grapheme break property (8 bits),
offset to multichar other cases or zero (8 bits), offset to other case or zero
(32 bits, signed), script extension (8 bits), bidi class (8 bits), bool
properties offset (8 bits), and a dummy 8-bit field to make the whole thing a
multiple of 4 bytes. */
\n""")

write_records(records, record_size)
write_table(min_stage1, 'PRIV(ucd_stage1)')
write_table(min_stage2, 'PRIV(ucd_stage2)', min_block_size)

f.write("#if UCD_BLOCK_SIZE != %d\n" % min_block_size)
f.write("""\
#error Please correct UCD_BLOCK_SIZE in pcre2_internal.h
#endif
#endif  /* SUPPORT_UNICODE */

#endif  /* PCRE2_PCRE2TEST */

/* End of pcre2_ucd.c */
""")

f.close

# End
