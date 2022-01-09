/*************************************************
*      Perl-Compatible Regular Expressions       *
*************************************************/

/* PCRE is a library of functions to support regular expressions whose syntax
and semantics are as close as possible to those of the Perl 5 language.

                       Written by Philip Hazel
     Original API code Copyright (c) 1997-2012 University of Cambridge
          New API code Copyright (c) 2016-2022 University of Cambridge

This module is auto-generated from Unicode data files. DO NOT EDIT MANUALLY!
Instead, modify the maint/GenerateUcpTables.py script and run it to generate
a new version of this code.

-----------------------------------------------------------------------------
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

    * Neither the name of the University of Cambridge nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
-----------------------------------------------------------------------------
*/

#ifdef SUPPORT_UNICODE

/* The PRIV(utt)[] table below translates Unicode property names into type and
code values. It is searched by binary chop, so must be in collating sequence of
name. Originally, the table contained pointers to the name strings in the first
field of each entry. However, that leads to a large number of relocations when
a shared library is dynamically loaded. A significant reduction is made by
putting all the names into a single, large string and using offsets instead.
All letters are lower cased, and underscores are removed, in accordance with
the "loose matching" rules that Unicode advises and Perl uses. */

#define STRING_adlam0 STR_a STR_d STR_l STR_a STR_m "\0"
#define STRING_adlm0 STR_a STR_d STR_l STR_m "\0"
#define STRING_aghb0 STR_a STR_g STR_h STR_b "\0"
#define STRING_ahex0 STR_a STR_h STR_e STR_x "\0"
#define STRING_ahom0 STR_a STR_h STR_o STR_m "\0"
#define STRING_alpha0 STR_a STR_l STR_p STR_h STR_a "\0"
#define STRING_alphabetic0 STR_a STR_l STR_p STR_h STR_a STR_b STR_e STR_t STR_i STR_c "\0"
#define STRING_anatolianhieroglyphs0 STR_a STR_n STR_a STR_t STR_o STR_l STR_i STR_a STR_n STR_h STR_i STR_e STR_r STR_o STR_g STR_l STR_y STR_p STR_h STR_s "\0"
#define STRING_any0 STR_a STR_n STR_y "\0"
#define STRING_arab0 STR_a STR_r STR_a STR_b "\0"
#define STRING_arabic0 STR_a STR_r STR_a STR_b STR_i STR_c "\0"
#define STRING_armenian0 STR_a STR_r STR_m STR_e STR_n STR_i STR_a STR_n "\0"
#define STRING_armi0 STR_a STR_r STR_m STR_i "\0"
#define STRING_armn0 STR_a STR_r STR_m STR_n "\0"
#define STRING_ascii0 STR_a STR_s STR_c STR_i STR_i "\0"
#define STRING_asciihexdigit0 STR_a STR_s STR_c STR_i STR_i STR_h STR_e STR_x STR_d STR_i STR_g STR_i STR_t "\0"
#define STRING_avestan0 STR_a STR_v STR_e STR_s STR_t STR_a STR_n "\0"
#define STRING_avst0 STR_a STR_v STR_s STR_t "\0"
#define STRING_bali0 STR_b STR_a STR_l STR_i "\0"
#define STRING_balinese0 STR_b STR_a STR_l STR_i STR_n STR_e STR_s STR_e "\0"
#define STRING_bamu0 STR_b STR_a STR_m STR_u "\0"
#define STRING_bamum0 STR_b STR_a STR_m STR_u STR_m "\0"
#define STRING_bass0 STR_b STR_a STR_s STR_s "\0"
#define STRING_bassavah0 STR_b STR_a STR_s STR_s STR_a STR_v STR_a STR_h "\0"
#define STRING_batak0 STR_b STR_a STR_t STR_a STR_k "\0"
#define STRING_batk0 STR_b STR_a STR_t STR_k "\0"
#define STRING_beng0 STR_b STR_e STR_n STR_g "\0"
#define STRING_bengali0 STR_b STR_e STR_n STR_g STR_a STR_l STR_i "\0"
#define STRING_bhaiksuki0 STR_b STR_h STR_a STR_i STR_k STR_s STR_u STR_k STR_i "\0"
#define STRING_bhks0 STR_b STR_h STR_k STR_s "\0"
#define STRING_bidial0 STR_b STR_i STR_d STR_i STR_a STR_l "\0"
#define STRING_bidian0 STR_b STR_i STR_d STR_i STR_a STR_n "\0"
#define STRING_bidib0 STR_b STR_i STR_d STR_i STR_b "\0"
#define STRING_bidibn0 STR_b STR_i STR_d STR_i STR_b STR_n "\0"
#define STRING_bidic0 STR_b STR_i STR_d STR_i STR_c "\0"
#define STRING_bidicontrol0 STR_b STR_i STR_d STR_i STR_c STR_o STR_n STR_t STR_r STR_o STR_l "\0"
#define STRING_bidics0 STR_b STR_i STR_d STR_i STR_c STR_s "\0"
#define STRING_bidien0 STR_b STR_i STR_d STR_i STR_e STR_n "\0"
#define STRING_bidies0 STR_b STR_i STR_d STR_i STR_e STR_s "\0"
#define STRING_bidiet0 STR_b STR_i STR_d STR_i STR_e STR_t "\0"
#define STRING_bidifsi0 STR_b STR_i STR_d STR_i STR_f STR_s STR_i "\0"
#define STRING_bidil0 STR_b STR_i STR_d STR_i STR_l "\0"
#define STRING_bidilre0 STR_b STR_i STR_d STR_i STR_l STR_r STR_e "\0"
#define STRING_bidilri0 STR_b STR_i STR_d STR_i STR_l STR_r STR_i "\0"
#define STRING_bidilro0 STR_b STR_i STR_d STR_i STR_l STR_r STR_o "\0"
#define STRING_bidim0 STR_b STR_i STR_d STR_i STR_m "\0"
#define STRING_bidimirrored0 STR_b STR_i STR_d STR_i STR_m STR_i STR_r STR_r STR_o STR_r STR_e STR_d "\0"
#define STRING_bidinsm0 STR_b STR_i STR_d STR_i STR_n STR_s STR_m "\0"
#define STRING_bidion0 STR_b STR_i STR_d STR_i STR_o STR_n "\0"
#define STRING_bidipdf0 STR_b STR_i STR_d STR_i STR_p STR_d STR_f "\0"
#define STRING_bidipdi0 STR_b STR_i STR_d STR_i STR_p STR_d STR_i "\0"
#define STRING_bidir0 STR_b STR_i STR_d STR_i STR_r "\0"
#define STRING_bidirle0 STR_b STR_i STR_d STR_i STR_r STR_l STR_e "\0"
#define STRING_bidirli0 STR_b STR_i STR_d STR_i STR_r STR_l STR_i "\0"
#define STRING_bidirlo0 STR_b STR_i STR_d STR_i STR_r STR_l STR_o "\0"
#define STRING_bidis0 STR_b STR_i STR_d STR_i STR_s "\0"
#define STRING_bidiws0 STR_b STR_i STR_d STR_i STR_w STR_s "\0"
#define STRING_bopo0 STR_b STR_o STR_p STR_o "\0"
#define STRING_bopomofo0 STR_b STR_o STR_p STR_o STR_m STR_o STR_f STR_o "\0"
#define STRING_brah0 STR_b STR_r STR_a STR_h "\0"
#define STRING_brahmi0 STR_b STR_r STR_a STR_h STR_m STR_i "\0"
#define STRING_brai0 STR_b STR_r STR_a STR_i "\0"
#define STRING_braille0 STR_b STR_r STR_a STR_i STR_l STR_l STR_e "\0"
#define STRING_bugi0 STR_b STR_u STR_g STR_i "\0"
#define STRING_buginese0 STR_b STR_u STR_g STR_i STR_n STR_e STR_s STR_e "\0"
#define STRING_buhd0 STR_b STR_u STR_h STR_d "\0"
#define STRING_buhid0 STR_b STR_u STR_h STR_i STR_d "\0"
#define STRING_c0 STR_c "\0"
#define STRING_cakm0 STR_c STR_a STR_k STR_m "\0"
#define STRING_canadianaboriginal0 STR_c STR_a STR_n STR_a STR_d STR_i STR_a STR_n STR_a STR_b STR_o STR_r STR_i STR_g STR_i STR_n STR_a STR_l "\0"
#define STRING_cans0 STR_c STR_a STR_n STR_s "\0"
#define STRING_cari0 STR_c STR_a STR_r STR_i "\0"
#define STRING_carian0 STR_c STR_a STR_r STR_i STR_a STR_n "\0"
#define STRING_cased0 STR_c STR_a STR_s STR_e STR_d "\0"
#define STRING_cased0 STR_c STR_a STR_s STR_e STR_d "\0"
#define STRING_caseignorable0 STR_c STR_a STR_s STR_e STR_i STR_g STR_n STR_o STR_r STR_a STR_b STR_l STR_e "\0"
#define STRING_caucasianalbanian0 STR_c STR_a STR_u STR_c STR_a STR_s STR_i STR_a STR_n STR_a STR_l STR_b STR_a STR_n STR_i STR_a STR_n "\0"
#define STRING_cc0 STR_c STR_c "\0"
#define STRING_cf0 STR_c STR_f "\0"
#define STRING_chakma0 STR_c STR_h STR_a STR_k STR_m STR_a "\0"
#define STRING_cham0 STR_c STR_h STR_a STR_m "\0"
#define STRING_changeswhencasefolded0 STR_c STR_h STR_a STR_n STR_g STR_e STR_s STR_w STR_h STR_e STR_n STR_c STR_a STR_s STR_e STR_f STR_o STR_l STR_d STR_e STR_d "\0"
#define STRING_changeswhencasemapped0 STR_c STR_h STR_a STR_n STR_g STR_e STR_s STR_w STR_h STR_e STR_n STR_c STR_a STR_s STR_e STR_m STR_a STR_p STR_p STR_e STR_d "\0"
#define STRING_changeswhenlowercased0 STR_c STR_h STR_a STR_n STR_g STR_e STR_s STR_w STR_h STR_e STR_n STR_l STR_o STR_w STR_e STR_r STR_c STR_a STR_s STR_e STR_d "\0"
#define STRING_changeswhentitlecased0 STR_c STR_h STR_a STR_n STR_g STR_e STR_s STR_w STR_h STR_e STR_n STR_t STR_i STR_t STR_l STR_e STR_c STR_a STR_s STR_e STR_d "\0"
#define STRING_changeswhenuppercased0 STR_c STR_h STR_a STR_n STR_g STR_e STR_s STR_w STR_h STR_e STR_n STR_u STR_p STR_p STR_e STR_r STR_c STR_a STR_s STR_e STR_d "\0"
#define STRING_cher0 STR_c STR_h STR_e STR_r "\0"
#define STRING_cherokee0 STR_c STR_h STR_e STR_r STR_o STR_k STR_e STR_e "\0"
#define STRING_chorasmian0 STR_c STR_h STR_o STR_r STR_a STR_s STR_m STR_i STR_a STR_n "\0"
#define STRING_chrs0 STR_c STR_h STR_r STR_s "\0"
#define STRING_ci0 STR_c STR_i "\0"
#define STRING_cn0 STR_c STR_n "\0"
#define STRING_co0 STR_c STR_o "\0"
#define STRING_common0 STR_c STR_o STR_m STR_m STR_o STR_n "\0"
#define STRING_copt0 STR_c STR_o STR_p STR_t "\0"
#define STRING_coptic0 STR_c STR_o STR_p STR_t STR_i STR_c "\0"
#define STRING_cpmn0 STR_c STR_p STR_m STR_n "\0"
#define STRING_cprt0 STR_c STR_p STR_r STR_t "\0"
#define STRING_cs0 STR_c STR_s "\0"
#define STRING_cuneiform0 STR_c STR_u STR_n STR_e STR_i STR_f STR_o STR_r STR_m "\0"
#define STRING_cwcf0 STR_c STR_w STR_c STR_f "\0"
#define STRING_cwcm0 STR_c STR_w STR_c STR_m "\0"
#define STRING_cwl0 STR_c STR_w STR_l "\0"
#define STRING_cwt0 STR_c STR_w STR_t "\0"
#define STRING_cwu0 STR_c STR_w STR_u "\0"
#define STRING_cypriot0 STR_c STR_y STR_p STR_r STR_i STR_o STR_t "\0"
#define STRING_cyprominoan0 STR_c STR_y STR_p STR_r STR_o STR_m STR_i STR_n STR_o STR_a STR_n "\0"
#define STRING_cyrillic0 STR_c STR_y STR_r STR_i STR_l STR_l STR_i STR_c "\0"
#define STRING_cyrl0 STR_c STR_y STR_r STR_l "\0"
#define STRING_dash0 STR_d STR_a STR_s STR_h "\0"
#define STRING_dash0 STR_d STR_a STR_s STR_h "\0"
#define STRING_defaultignorablecodepoint0 STR_d STR_e STR_f STR_a STR_u STR_l STR_t STR_i STR_g STR_n STR_o STR_r STR_a STR_b STR_l STR_e STR_c STR_o STR_d STR_e STR_p STR_o STR_i STR_n STR_t "\0"
#define STRING_dep0 STR_d STR_e STR_p "\0"
#define STRING_deprecated0 STR_d STR_e STR_p STR_r STR_e STR_c STR_a STR_t STR_e STR_d "\0"
#define STRING_deseret0 STR_d STR_e STR_s STR_e STR_r STR_e STR_t "\0"
#define STRING_deva0 STR_d STR_e STR_v STR_a "\0"
#define STRING_devanagari0 STR_d STR_e STR_v STR_a STR_n STR_a STR_g STR_a STR_r STR_i "\0"
#define STRING_di0 STR_d STR_i "\0"
#define STRING_dia0 STR_d STR_i STR_a "\0"
#define STRING_diacritic0 STR_d STR_i STR_a STR_c STR_r STR_i STR_t STR_i STR_c "\0"
#define STRING_diak0 STR_d STR_i STR_a STR_k "\0"
#define STRING_divesakuru0 STR_d STR_i STR_v STR_e STR_s STR_a STR_k STR_u STR_r STR_u "\0"
#define STRING_dogr0 STR_d STR_o STR_g STR_r "\0"
#define STRING_dogra0 STR_d STR_o STR_g STR_r STR_a "\0"
#define STRING_dsrt0 STR_d STR_s STR_r STR_t "\0"
#define STRING_dupl0 STR_d STR_u STR_p STR_l "\0"
#define STRING_duployan0 STR_d STR_u STR_p STR_l STR_o STR_y STR_a STR_n "\0"
#define STRING_ebase0 STR_e STR_b STR_a STR_s STR_e "\0"
#define STRING_ecomp0 STR_e STR_c STR_o STR_m STR_p "\0"
#define STRING_egyp0 STR_e STR_g STR_y STR_p "\0"
#define STRING_egyptianhieroglyphs0 STR_e STR_g STR_y STR_p STR_t STR_i STR_a STR_n STR_h STR_i STR_e STR_r STR_o STR_g STR_l STR_y STR_p STR_h STR_s "\0"
#define STRING_elba0 STR_e STR_l STR_b STR_a "\0"
#define STRING_elbasan0 STR_e STR_l STR_b STR_a STR_s STR_a STR_n "\0"
#define STRING_elym0 STR_e STR_l STR_y STR_m "\0"
#define STRING_elymaic0 STR_e STR_l STR_y STR_m STR_a STR_i STR_c "\0"
#define STRING_emod0 STR_e STR_m STR_o STR_d "\0"
#define STRING_emoji0 STR_e STR_m STR_o STR_j STR_i "\0"
#define STRING_emoji0 STR_e STR_m STR_o STR_j STR_i "\0"
#define STRING_emojicomponent0 STR_e STR_m STR_o STR_j STR_i STR_c STR_o STR_m STR_p STR_o STR_n STR_e STR_n STR_t "\0"
#define STRING_emojimodifier0 STR_e STR_m STR_o STR_j STR_i STR_m STR_o STR_d STR_i STR_f STR_i STR_e STR_r "\0"
#define STRING_emojimodifierbase0 STR_e STR_m STR_o STR_j STR_i STR_m STR_o STR_d STR_i STR_f STR_i STR_e STR_r STR_b STR_a STR_s STR_e "\0"
#define STRING_emojipresentation0 STR_e STR_m STR_o STR_j STR_i STR_p STR_r STR_e STR_s STR_e STR_n STR_t STR_a STR_t STR_i STR_o STR_n "\0"
#define STRING_epres0 STR_e STR_p STR_r STR_e STR_s "\0"
#define STRING_ethi0 STR_e STR_t STR_h STR_i "\0"
#define STRING_ethiopic0 STR_e STR_t STR_h STR_i STR_o STR_p STR_i STR_c "\0"
#define STRING_ext0 STR_e STR_x STR_t "\0"
#define STRING_extendedpictographic0 STR_e STR_x STR_t STR_e STR_n STR_d STR_e STR_d STR_p STR_i STR_c STR_t STR_o STR_g STR_r STR_a STR_p STR_h STR_i STR_c "\0"
#define STRING_extender0 STR_e STR_x STR_t STR_e STR_n STR_d STR_e STR_r "\0"
#define STRING_extpict0 STR_e STR_x STR_t STR_p STR_i STR_c STR_t "\0"
#define STRING_geor0 STR_g STR_e STR_o STR_r "\0"
#define STRING_georgian0 STR_g STR_e STR_o STR_r STR_g STR_i STR_a STR_n "\0"
#define STRING_glag0 STR_g STR_l STR_a STR_g "\0"
#define STRING_glagolitic0 STR_g STR_l STR_a STR_g STR_o STR_l STR_i STR_t STR_i STR_c "\0"
#define STRING_gong0 STR_g STR_o STR_n STR_g "\0"
#define STRING_gonm0 STR_g STR_o STR_n STR_m "\0"
#define STRING_goth0 STR_g STR_o STR_t STR_h "\0"
#define STRING_gothic0 STR_g STR_o STR_t STR_h STR_i STR_c "\0"
#define STRING_gran0 STR_g STR_r STR_a STR_n "\0"
#define STRING_grantha0 STR_g STR_r STR_a STR_n STR_t STR_h STR_a "\0"
#define STRING_graphemebase0 STR_g STR_r STR_a STR_p STR_h STR_e STR_m STR_e STR_b STR_a STR_s STR_e "\0"
#define STRING_graphemeextend0 STR_g STR_r STR_a STR_p STR_h STR_e STR_m STR_e STR_e STR_x STR_t STR_e STR_n STR_d "\0"
#define STRING_graphemelink0 STR_g STR_r STR_a STR_p STR_h STR_e STR_m STR_e STR_l STR_i STR_n STR_k "\0"
#define STRING_grbase0 STR_g STR_r STR_b STR_a STR_s STR_e "\0"
#define STRING_greek0 STR_g STR_r STR_e STR_e STR_k "\0"
#define STRING_grek0 STR_g STR_r STR_e STR_k "\0"
#define STRING_grext0 STR_g STR_r STR_e STR_x STR_t "\0"
#define STRING_grlink0 STR_g STR_r STR_l STR_i STR_n STR_k "\0"
#define STRING_gujarati0 STR_g STR_u STR_j STR_a STR_r STR_a STR_t STR_i "\0"
#define STRING_gujr0 STR_g STR_u STR_j STR_r "\0"
#define STRING_gunjalagondi0 STR_g STR_u STR_n STR_j STR_a STR_l STR_a STR_g STR_o STR_n STR_d STR_i "\0"
#define STRING_gurmukhi0 STR_g STR_u STR_r STR_m STR_u STR_k STR_h STR_i "\0"
#define STRING_guru0 STR_g STR_u STR_r STR_u "\0"
#define STRING_han0 STR_h STR_a STR_n "\0"
#define STRING_hang0 STR_h STR_a STR_n STR_g "\0"
#define STRING_hangul0 STR_h STR_a STR_n STR_g STR_u STR_l "\0"
#define STRING_hani0 STR_h STR_a STR_n STR_i "\0"
#define STRING_hanifirohingya0 STR_h STR_a STR_n STR_i STR_f STR_i STR_r STR_o STR_h STR_i STR_n STR_g STR_y STR_a "\0"
#define STRING_hano0 STR_h STR_a STR_n STR_o "\0"
#define STRING_hanunoo0 STR_h STR_a STR_n STR_u STR_n STR_o STR_o "\0"
#define STRING_hatr0 STR_h STR_a STR_t STR_r "\0"
#define STRING_hatran0 STR_h STR_a STR_t STR_r STR_a STR_n "\0"
#define STRING_hebr0 STR_h STR_e STR_b STR_r "\0"
#define STRING_hebrew0 STR_h STR_e STR_b STR_r STR_e STR_w "\0"
#define STRING_hex0 STR_h STR_e STR_x "\0"
#define STRING_hexdigit0 STR_h STR_e STR_x STR_d STR_i STR_g STR_i STR_t "\0"
#define STRING_hira0 STR_h STR_i STR_r STR_a "\0"
#define STRING_hiragana0 STR_h STR_i STR_r STR_a STR_g STR_a STR_n STR_a "\0"
#define STRING_hluw0 STR_h STR_l STR_u STR_w "\0"
#define STRING_hmng0 STR_h STR_m STR_n STR_g "\0"
#define STRING_hmnp0 STR_h STR_m STR_n STR_p "\0"
#define STRING_hung0 STR_h STR_u STR_n STR_g "\0"
#define STRING_idc0 STR_i STR_d STR_c "\0"
#define STRING_idcontinue0 STR_i STR_d STR_c STR_o STR_n STR_t STR_i STR_n STR_u STR_e "\0"
#define STRING_ideo0 STR_i STR_d STR_e STR_o "\0"
#define STRING_ideographic0 STR_i STR_d STR_e STR_o STR_g STR_r STR_a STR_p STR_h STR_i STR_c "\0"
#define STRING_ids0 STR_i STR_d STR_s "\0"
#define STRING_idsb0 STR_i STR_d STR_s STR_b "\0"
#define STRING_idsbinaryoperator0 STR_i STR_d STR_s STR_b STR_i STR_n STR_a STR_r STR_y STR_o STR_p STR_e STR_r STR_a STR_t STR_o STR_r "\0"
#define STRING_idst0 STR_i STR_d STR_s STR_t "\0"
#define STRING_idstart0 STR_i STR_d STR_s STR_t STR_a STR_r STR_t "\0"
#define STRING_idstrinaryoperator0 STR_i STR_d STR_s STR_t STR_r STR_i STR_n STR_a STR_r STR_y STR_o STR_p STR_e STR_r STR_a STR_t STR_o STR_r "\0"
#define STRING_imperialaramaic0 STR_i STR_m STR_p STR_e STR_r STR_i STR_a STR_l STR_a STR_r STR_a STR_m STR_a STR_i STR_c "\0"
#define STRING_inherited0 STR_i STR_n STR_h STR_e STR_r STR_i STR_t STR_e STR_d "\0"
#define STRING_inscriptionalpahlavi0 STR_i STR_n STR_s STR_c STR_r STR_i STR_p STR_t STR_i STR_o STR_n STR_a STR_l STR_p STR_a STR_h STR_l STR_a STR_v STR_i "\0"
#define STRING_inscriptionalparthian0 STR_i STR_n STR_s STR_c STR_r STR_i STR_p STR_t STR_i STR_o STR_n STR_a STR_l STR_p STR_a STR_r STR_t STR_h STR_i STR_a STR_n "\0"
#define STRING_ital0 STR_i STR_t STR_a STR_l "\0"
#define STRING_java0 STR_j STR_a STR_v STR_a "\0"
#define STRING_javanese0 STR_j STR_a STR_v STR_a STR_n STR_e STR_s STR_e "\0"
#define STRING_joinc0 STR_j STR_o STR_i STR_n STR_c "\0"
#define STRING_joincontrol0 STR_j STR_o STR_i STR_n STR_c STR_o STR_n STR_t STR_r STR_o STR_l "\0"
#define STRING_kaithi0 STR_k STR_a STR_i STR_t STR_h STR_i "\0"
#define STRING_kali0 STR_k STR_a STR_l STR_i "\0"
#define STRING_kana0 STR_k STR_a STR_n STR_a "\0"
#define STRING_kannada0 STR_k STR_a STR_n STR_n STR_a STR_d STR_a "\0"
#define STRING_katakana0 STR_k STR_a STR_t STR_a STR_k STR_a STR_n STR_a "\0"
#define STRING_kayahli0 STR_k STR_a STR_y STR_a STR_h STR_l STR_i "\0"
#define STRING_khar0 STR_k STR_h STR_a STR_r "\0"
#define STRING_kharoshthi0 STR_k STR_h STR_a STR_r STR_o STR_s STR_h STR_t STR_h STR_i "\0"
#define STRING_khitansmallscript0 STR_k STR_h STR_i STR_t STR_a STR_n STR_s STR_m STR_a STR_l STR_l STR_s STR_c STR_r STR_i STR_p STR_t "\0"
#define STRING_khmer0 STR_k STR_h STR_m STR_e STR_r "\0"
#define STRING_khmr0 STR_k STR_h STR_m STR_r "\0"
#define STRING_khoj0 STR_k STR_h STR_o STR_j "\0"
#define STRING_khojki0 STR_k STR_h STR_o STR_j STR_k STR_i "\0"
#define STRING_khudawadi0 STR_k STR_h STR_u STR_d STR_a STR_w STR_a STR_d STR_i "\0"
#define STRING_kits0 STR_k STR_i STR_t STR_s "\0"
#define STRING_knda0 STR_k STR_n STR_d STR_a "\0"
#define STRING_kthi0 STR_k STR_t STR_h STR_i "\0"
#define STRING_l0 STR_l "\0"
#define STRING_l_AMPERSAND0 STR_l STR_AMPERSAND "\0"
#define STRING_lana0 STR_l STR_a STR_n STR_a "\0"
#define STRING_lao0 STR_l STR_a STR_o "\0"
#define STRING_laoo0 STR_l STR_a STR_o STR_o "\0"
#define STRING_latin0 STR_l STR_a STR_t STR_i STR_n "\0"
#define STRING_latn0 STR_l STR_a STR_t STR_n "\0"
#define STRING_lc0 STR_l STR_c "\0"
#define STRING_lepc0 STR_l STR_e STR_p STR_c "\0"
#define STRING_lepcha0 STR_l STR_e STR_p STR_c STR_h STR_a "\0"
#define STRING_limb0 STR_l STR_i STR_m STR_b "\0"
#define STRING_limbu0 STR_l STR_i STR_m STR_b STR_u "\0"
#define STRING_lina0 STR_l STR_i STR_n STR_a "\0"
#define STRING_linb0 STR_l STR_i STR_n STR_b "\0"
#define STRING_lineara0 STR_l STR_i STR_n STR_e STR_a STR_r STR_a "\0"
#define STRING_linearb0 STR_l STR_i STR_n STR_e STR_a STR_r STR_b "\0"
#define STRING_lisu0 STR_l STR_i STR_s STR_u "\0"
#define STRING_ll0 STR_l STR_l "\0"
#define STRING_lm0 STR_l STR_m "\0"
#define STRING_lo0 STR_l STR_o "\0"
#define STRING_loe0 STR_l STR_o STR_e "\0"
#define STRING_logicalorderexception0 STR_l STR_o STR_g STR_i STR_c STR_a STR_l STR_o STR_r STR_d STR_e STR_r STR_e STR_x STR_c STR_e STR_p STR_t STR_i STR_o STR_n "\0"
#define STRING_lower0 STR_l STR_o STR_w STR_e STR_r "\0"
#define STRING_lowercase0 STR_l STR_o STR_w STR_e STR_r STR_c STR_a STR_s STR_e "\0"
#define STRING_lt0 STR_l STR_t "\0"
#define STRING_lu0 STR_l STR_u "\0"
#define STRING_lyci0 STR_l STR_y STR_c STR_i "\0"
#define STRING_lycian0 STR_l STR_y STR_c STR_i STR_a STR_n "\0"
#define STRING_lydi0 STR_l STR_y STR_d STR_i "\0"
#define STRING_lydian0 STR_l STR_y STR_d STR_i STR_a STR_n "\0"
#define STRING_m0 STR_m "\0"
#define STRING_mahajani0 STR_m STR_a STR_h STR_a STR_j STR_a STR_n STR_i "\0"
#define STRING_mahj0 STR_m STR_a STR_h STR_j "\0"
#define STRING_maka0 STR_m STR_a STR_k STR_a "\0"
#define STRING_makasar0 STR_m STR_a STR_k STR_a STR_s STR_a STR_r "\0"
#define STRING_malayalam0 STR_m STR_a STR_l STR_a STR_y STR_a STR_l STR_a STR_m "\0"
#define STRING_mand0 STR_m STR_a STR_n STR_d "\0"
#define STRING_mandaic0 STR_m STR_a STR_n STR_d STR_a STR_i STR_c "\0"
#define STRING_mani0 STR_m STR_a STR_n STR_i "\0"
#define STRING_manichaean0 STR_m STR_a STR_n STR_i STR_c STR_h STR_a STR_e STR_a STR_n "\0"
#define STRING_marc0 STR_m STR_a STR_r STR_c "\0"
#define STRING_marchen0 STR_m STR_a STR_r STR_c STR_h STR_e STR_n "\0"
#define STRING_masaramgondi0 STR_m STR_a STR_s STR_a STR_r STR_a STR_m STR_g STR_o STR_n STR_d STR_i "\0"
#define STRING_math0 STR_m STR_a STR_t STR_h "\0"
#define STRING_math0 STR_m STR_a STR_t STR_h "\0"
#define STRING_mc0 STR_m STR_c "\0"
#define STRING_me0 STR_m STR_e "\0"
#define STRING_medefaidrin0 STR_m STR_e STR_d STR_e STR_f STR_a STR_i STR_d STR_r STR_i STR_n "\0"
#define STRING_medf0 STR_m STR_e STR_d STR_f "\0"
#define STRING_meeteimayek0 STR_m STR_e STR_e STR_t STR_e STR_i STR_m STR_a STR_y STR_e STR_k "\0"
#define STRING_mend0 STR_m STR_e STR_n STR_d "\0"
#define STRING_mendekikakui0 STR_m STR_e STR_n STR_d STR_e STR_k STR_i STR_k STR_a STR_k STR_u STR_i "\0"
#define STRING_merc0 STR_m STR_e STR_r STR_c "\0"
#define STRING_mero0 STR_m STR_e STR_r STR_o "\0"
#define STRING_meroiticcursive0 STR_m STR_e STR_r STR_o STR_i STR_t STR_i STR_c STR_c STR_u STR_r STR_s STR_i STR_v STR_e "\0"
#define STRING_meroitichieroglyphs0 STR_m STR_e STR_r STR_o STR_i STR_t STR_i STR_c STR_h STR_i STR_e STR_r STR_o STR_g STR_l STR_y STR_p STR_h STR_s "\0"
#define STRING_miao0 STR_m STR_i STR_a STR_o "\0"
#define STRING_mlym0 STR_m STR_l STR_y STR_m "\0"
#define STRING_mn0 STR_m STR_n "\0"
#define STRING_modi0 STR_m STR_o STR_d STR_i "\0"
#define STRING_mong0 STR_m STR_o STR_n STR_g "\0"
#define STRING_mongolian0 STR_m STR_o STR_n STR_g STR_o STR_l STR_i STR_a STR_n "\0"
#define STRING_mro0 STR_m STR_r STR_o "\0"
#define STRING_mroo0 STR_m STR_r STR_o STR_o "\0"
#define STRING_mtei0 STR_m STR_t STR_e STR_i "\0"
#define STRING_mult0 STR_m STR_u STR_l STR_t "\0"
#define STRING_multani0 STR_m STR_u STR_l STR_t STR_a STR_n STR_i "\0"
#define STRING_myanmar0 STR_m STR_y STR_a STR_n STR_m STR_a STR_r "\0"
#define STRING_mymr0 STR_m STR_y STR_m STR_r "\0"
#define STRING_n0 STR_n "\0"
#define STRING_nabataean0 STR_n STR_a STR_b STR_a STR_t STR_a STR_e STR_a STR_n "\0"
#define STRING_nand0 STR_n STR_a STR_n STR_d "\0"
#define STRING_nandinagari0 STR_n STR_a STR_n STR_d STR_i STR_n STR_a STR_g STR_a STR_r STR_i "\0"
#define STRING_narb0 STR_n STR_a STR_r STR_b "\0"
#define STRING_nbat0 STR_n STR_b STR_a STR_t "\0"
#define STRING_nchar0 STR_n STR_c STR_h STR_a STR_r "\0"
#define STRING_nd0 STR_n STR_d "\0"
#define STRING_newa0 STR_n STR_e STR_w STR_a "\0"
#define STRING_newtailue0 STR_n STR_e STR_w STR_t STR_a STR_i STR_l STR_u STR_e "\0"
#define STRING_nko0 STR_n STR_k STR_o "\0"
#define STRING_nkoo0 STR_n STR_k STR_o STR_o "\0"
#define STRING_nl0 STR_n STR_l "\0"
#define STRING_no0 STR_n STR_o "\0"
#define STRING_noncharactercodepoint0 STR_n STR_o STR_n STR_c STR_h STR_a STR_r STR_a STR_c STR_t STR_e STR_r STR_c STR_o STR_d STR_e STR_p STR_o STR_i STR_n STR_t "\0"
#define STRING_nshu0 STR_n STR_s STR_h STR_u "\0"
#define STRING_nushu0 STR_n STR_u STR_s STR_h STR_u "\0"
#define STRING_nyiakengpuachuehmong0 STR_n STR_y STR_i STR_a STR_k STR_e STR_n STR_g STR_p STR_u STR_a STR_c STR_h STR_u STR_e STR_h STR_m STR_o STR_n STR_g "\0"
#define STRING_ogam0 STR_o STR_g STR_a STR_m "\0"
#define STRING_ogham0 STR_o STR_g STR_h STR_a STR_m "\0"
#define STRING_olchiki0 STR_o STR_l STR_c STR_h STR_i STR_k STR_i "\0"
#define STRING_olck0 STR_o STR_l STR_c STR_k "\0"
#define STRING_oldhungarian0 STR_o STR_l STR_d STR_h STR_u STR_n STR_g STR_a STR_r STR_i STR_a STR_n "\0"
#define STRING_olditalic0 STR_o STR_l STR_d STR_i STR_t STR_a STR_l STR_i STR_c "\0"
#define STRING_oldnortharabian0 STR_o STR_l STR_d STR_n STR_o STR_r STR_t STR_h STR_a STR_r STR_a STR_b STR_i STR_a STR_n "\0"
#define STRING_oldpermic0 STR_o STR_l STR_d STR_p STR_e STR_r STR_m STR_i STR_c "\0"
#define STRING_oldpersian0 STR_o STR_l STR_d STR_p STR_e STR_r STR_s STR_i STR_a STR_n "\0"
#define STRING_oldsogdian0 STR_o STR_l STR_d STR_s STR_o STR_g STR_d STR_i STR_a STR_n "\0"
#define STRING_oldsoutharabian0 STR_o STR_l STR_d STR_s STR_o STR_u STR_t STR_h STR_a STR_r STR_a STR_b STR_i STR_a STR_n "\0"
#define STRING_oldturkic0 STR_o STR_l STR_d STR_t STR_u STR_r STR_k STR_i STR_c "\0"
#define STRING_olduyghur0 STR_o STR_l STR_d STR_u STR_y STR_g STR_h STR_u STR_r "\0"
#define STRING_oriya0 STR_o STR_r STR_i STR_y STR_a "\0"
#define STRING_orkh0 STR_o STR_r STR_k STR_h "\0"
#define STRING_orya0 STR_o STR_r STR_y STR_a "\0"
#define STRING_osage0 STR_o STR_s STR_a STR_g STR_e "\0"
#define STRING_osge0 STR_o STR_s STR_g STR_e "\0"
#define STRING_osma0 STR_o STR_s STR_m STR_a "\0"
#define STRING_osmanya0 STR_o STR_s STR_m STR_a STR_n STR_y STR_a "\0"
#define STRING_ougr0 STR_o STR_u STR_g STR_r "\0"
#define STRING_p0 STR_p "\0"
#define STRING_pahawhhmong0 STR_p STR_a STR_h STR_a STR_w STR_h STR_h STR_m STR_o STR_n STR_g "\0"
#define STRING_palm0 STR_p STR_a STR_l STR_m "\0"
#define STRING_palmyrene0 STR_p STR_a STR_l STR_m STR_y STR_r STR_e STR_n STR_e "\0"
#define STRING_patsyn0 STR_p STR_a STR_t STR_s STR_y STR_n "\0"
#define STRING_patternsyntax0 STR_p STR_a STR_t STR_t STR_e STR_r STR_n STR_s STR_y STR_n STR_t STR_a STR_x "\0"
#define STRING_patternwhitespace0 STR_p STR_a STR_t STR_t STR_e STR_r STR_n STR_w STR_h STR_i STR_t STR_e STR_s STR_p STR_a STR_c STR_e "\0"
#define STRING_patws0 STR_p STR_a STR_t STR_w STR_s "\0"
#define STRING_pauc0 STR_p STR_a STR_u STR_c "\0"
#define STRING_paucinhau0 STR_p STR_a STR_u STR_c STR_i STR_n STR_h STR_a STR_u "\0"
#define STRING_pc0 STR_p STR_c "\0"
#define STRING_pcm0 STR_p STR_c STR_m "\0"
#define STRING_pd0 STR_p STR_d "\0"
#define STRING_pe0 STR_p STR_e "\0"
#define STRING_perm0 STR_p STR_e STR_r STR_m "\0"
#define STRING_pf0 STR_p STR_f "\0"
#define STRING_phag0 STR_p STR_h STR_a STR_g "\0"
#define STRING_phagspa0 STR_p STR_h STR_a STR_g STR_s STR_p STR_a "\0"
#define STRING_phli0 STR_p STR_h STR_l STR_i "\0"
#define STRING_phlp0 STR_p STR_h STR_l STR_p "\0"
#define STRING_phnx0 STR_p STR_h STR_n STR_x "\0"
#define STRING_phoenician0 STR_p STR_h STR_o STR_e STR_n STR_i STR_c STR_i STR_a STR_n "\0"
#define STRING_pi0 STR_p STR_i "\0"
#define STRING_plrd0 STR_p STR_l STR_r STR_d "\0"
#define STRING_po0 STR_p STR_o "\0"
#define STRING_prependedconcatenationmark0 STR_p STR_r STR_e STR_p STR_e STR_n STR_d STR_e STR_d STR_c STR_o STR_n STR_c STR_a STR_t STR_e STR_n STR_a STR_t STR_i STR_o STR_n STR_m STR_a STR_r STR_k "\0"
#define STRING_prti0 STR_p STR_r STR_t STR_i "\0"
#define STRING_ps0 STR_p STR_s "\0"
#define STRING_psalterpahlavi0 STR_p STR_s STR_a STR_l STR_t STR_e STR_r STR_p STR_a STR_h STR_l STR_a STR_v STR_i "\0"
#define STRING_qaac0 STR_q STR_a STR_a STR_c "\0"
#define STRING_qaai0 STR_q STR_a STR_a STR_i "\0"
#define STRING_qmark0 STR_q STR_m STR_a STR_r STR_k "\0"
#define STRING_quotationmark0 STR_q STR_u STR_o STR_t STR_a STR_t STR_i STR_o STR_n STR_m STR_a STR_r STR_k "\0"
#define STRING_radical0 STR_r STR_a STR_d STR_i STR_c STR_a STR_l "\0"
#define STRING_radical0 STR_r STR_a STR_d STR_i STR_c STR_a STR_l "\0"
#define STRING_regionalindicator0 STR_r STR_e STR_g STR_i STR_o STR_n STR_a STR_l STR_i STR_n STR_d STR_i STR_c STR_a STR_t STR_o STR_r "\0"
#define STRING_rejang0 STR_r STR_e STR_j STR_a STR_n STR_g "\0"
#define STRING_ri0 STR_r STR_i "\0"
#define STRING_rjng0 STR_r STR_j STR_n STR_g "\0"
#define STRING_rohg0 STR_r STR_o STR_h STR_g "\0"
#define STRING_runic0 STR_r STR_u STR_n STR_i STR_c "\0"
#define STRING_runr0 STR_r STR_u STR_n STR_r "\0"
#define STRING_s0 STR_s "\0"
#define STRING_samaritan0 STR_s STR_a STR_m STR_a STR_r STR_i STR_t STR_a STR_n "\0"
#define STRING_samr0 STR_s STR_a STR_m STR_r "\0"
#define STRING_sarb0 STR_s STR_a STR_r STR_b "\0"
#define STRING_saur0 STR_s STR_a STR_u STR_r "\0"
#define STRING_saurashtra0 STR_s STR_a STR_u STR_r STR_a STR_s STR_h STR_t STR_r STR_a "\0"
#define STRING_sc0 STR_s STR_c "\0"
#define STRING_sd0 STR_s STR_d "\0"
#define STRING_sentenceterminal0 STR_s STR_e STR_n STR_t STR_e STR_n STR_c STR_e STR_t STR_e STR_r STR_m STR_i STR_n STR_a STR_l "\0"
#define STRING_sgnw0 STR_s STR_g STR_n STR_w "\0"
#define STRING_sharada0 STR_s STR_h STR_a STR_r STR_a STR_d STR_a "\0"
#define STRING_shavian0 STR_s STR_h STR_a STR_v STR_i STR_a STR_n "\0"
#define STRING_shaw0 STR_s STR_h STR_a STR_w "\0"
#define STRING_shrd0 STR_s STR_h STR_r STR_d "\0"
#define STRING_sidd0 STR_s STR_i STR_d STR_d "\0"
#define STRING_siddham0 STR_s STR_i STR_d STR_d STR_h STR_a STR_m "\0"
#define STRING_signwriting0 STR_s STR_i STR_g STR_n STR_w STR_r STR_i STR_t STR_i STR_n STR_g "\0"
#define STRING_sind0 STR_s STR_i STR_n STR_d "\0"
#define STRING_sinh0 STR_s STR_i STR_n STR_h "\0"
#define STRING_sinhala0 STR_s STR_i STR_n STR_h STR_a STR_l STR_a "\0"
#define STRING_sk0 STR_s STR_k "\0"
#define STRING_sm0 STR_s STR_m "\0"
#define STRING_so0 STR_s STR_o "\0"
#define STRING_softdotted0 STR_s STR_o STR_f STR_t STR_d STR_o STR_t STR_t STR_e STR_d "\0"
#define STRING_sogd0 STR_s STR_o STR_g STR_d "\0"
#define STRING_sogdian0 STR_s STR_o STR_g STR_d STR_i STR_a STR_n "\0"
#define STRING_sogo0 STR_s STR_o STR_g STR_o "\0"
#define STRING_sora0 STR_s STR_o STR_r STR_a "\0"
#define STRING_sorasompeng0 STR_s STR_o STR_r STR_a STR_s STR_o STR_m STR_p STR_e STR_n STR_g "\0"
#define STRING_soyo0 STR_s STR_o STR_y STR_o "\0"
#define STRING_soyombo0 STR_s STR_o STR_y STR_o STR_m STR_b STR_o "\0"
#define STRING_space0 STR_s STR_p STR_a STR_c STR_e "\0"
#define STRING_sterm0 STR_s STR_t STR_e STR_r STR_m "\0"
#define STRING_sund0 STR_s STR_u STR_n STR_d "\0"
#define STRING_sundanese0 STR_s STR_u STR_n STR_d STR_a STR_n STR_e STR_s STR_e "\0"
#define STRING_sylo0 STR_s STR_y STR_l STR_o "\0"
#define STRING_sylotinagri0 STR_s STR_y STR_l STR_o STR_t STR_i STR_n STR_a STR_g STR_r STR_i "\0"
#define STRING_syrc0 STR_s STR_y STR_r STR_c "\0"
#define STRING_syriac0 STR_s STR_y STR_r STR_i STR_a STR_c "\0"
#define STRING_tagalog0 STR_t STR_a STR_g STR_a STR_l STR_o STR_g "\0"
#define STRING_tagb0 STR_t STR_a STR_g STR_b "\0"
#define STRING_tagbanwa0 STR_t STR_a STR_g STR_b STR_a STR_n STR_w STR_a "\0"
#define STRING_taile0 STR_t STR_a STR_i STR_l STR_e "\0"
#define STRING_taitham0 STR_t STR_a STR_i STR_t STR_h STR_a STR_m "\0"
#define STRING_taiviet0 STR_t STR_a STR_i STR_v STR_i STR_e STR_t "\0"
#define STRING_takr0 STR_t STR_a STR_k STR_r "\0"
#define STRING_takri0 STR_t STR_a STR_k STR_r STR_i "\0"
#define STRING_tale0 STR_t STR_a STR_l STR_e "\0"
#define STRING_talu0 STR_t STR_a STR_l STR_u "\0"
#define STRING_tamil0 STR_t STR_a STR_m STR_i STR_l "\0"
#define STRING_taml0 STR_t STR_a STR_m STR_l "\0"
#define STRING_tang0 STR_t STR_a STR_n STR_g "\0"
#define STRING_tangsa0 STR_t STR_a STR_n STR_g STR_s STR_a "\0"
#define STRING_tangut0 STR_t STR_a STR_n STR_g STR_u STR_t "\0"
#define STRING_tavt0 STR_t STR_a STR_v STR_t "\0"
#define STRING_telu0 STR_t STR_e STR_l STR_u "\0"
#define STRING_telugu0 STR_t STR_e STR_l STR_u STR_g STR_u "\0"
#define STRING_term0 STR_t STR_e STR_r STR_m "\0"
#define STRING_terminalpunctuation0 STR_t STR_e STR_r STR_m STR_i STR_n STR_a STR_l STR_p STR_u STR_n STR_c STR_t STR_u STR_a STR_t STR_i STR_o STR_n "\0"
#define STRING_tfng0 STR_t STR_f STR_n STR_g "\0"
#define STRING_tglg0 STR_t STR_g STR_l STR_g "\0"
#define STRING_thaa0 STR_t STR_h STR_a STR_a "\0"
#define STRING_thaana0 STR_t STR_h STR_a STR_a STR_n STR_a "\0"
#define STRING_thai0 STR_t STR_h STR_a STR_i "\0"
#define STRING_tibetan0 STR_t STR_i STR_b STR_e STR_t STR_a STR_n "\0"
#define STRING_tibt0 STR_t STR_i STR_b STR_t "\0"
#define STRING_tifinagh0 STR_t STR_i STR_f STR_i STR_n STR_a STR_g STR_h "\0"
#define STRING_tirh0 STR_t STR_i STR_r STR_h "\0"
#define STRING_tirhuta0 STR_t STR_i STR_r STR_h STR_u STR_t STR_a "\0"
#define STRING_tnsa0 STR_t STR_n STR_s STR_a "\0"
#define STRING_toto0 STR_t STR_o STR_t STR_o "\0"
#define STRING_ugar0 STR_u STR_g STR_a STR_r "\0"
#define STRING_ugaritic0 STR_u STR_g STR_a STR_r STR_i STR_t STR_i STR_c "\0"
#define STRING_uideo0 STR_u STR_i STR_d STR_e STR_o "\0"
#define STRING_unifiedideograph0 STR_u STR_n STR_i STR_f STR_i STR_e STR_d STR_i STR_d STR_e STR_o STR_g STR_r STR_a STR_p STR_h "\0"
#define STRING_unknown0 STR_u STR_n STR_k STR_n STR_o STR_w STR_n "\0"
#define STRING_upper0 STR_u STR_p STR_p STR_e STR_r "\0"
#define STRING_uppercase0 STR_u STR_p STR_p STR_e STR_r STR_c STR_a STR_s STR_e "\0"
#define STRING_vai0 STR_v STR_a STR_i "\0"
#define STRING_vaii0 STR_v STR_a STR_i STR_i "\0"
#define STRING_variationselector0 STR_v STR_a STR_r STR_i STR_a STR_t STR_i STR_o STR_n STR_s STR_e STR_l STR_e STR_c STR_t STR_o STR_r "\0"
#define STRING_vith0 STR_v STR_i STR_t STR_h "\0"
#define STRING_vithkuqi0 STR_v STR_i STR_t STR_h STR_k STR_u STR_q STR_i "\0"
#define STRING_vs0 STR_v STR_s "\0"
#define STRING_wancho0 STR_w STR_a STR_n STR_c STR_h STR_o "\0"
#define STRING_wara0 STR_w STR_a STR_r STR_a "\0"
#define STRING_warangciti0 STR_w STR_a STR_r STR_a STR_n STR_g STR_c STR_i STR_t STR_i "\0"
#define STRING_wcho0 STR_w STR_c STR_h STR_o "\0"
#define STRING_whitespace0 STR_w STR_h STR_i STR_t STR_e STR_s STR_p STR_a STR_c STR_e "\0"
#define STRING_wspace0 STR_w STR_s STR_p STR_a STR_c STR_e "\0"
#define STRING_xan0 STR_x STR_a STR_n "\0"
#define STRING_xidc0 STR_x STR_i STR_d STR_c "\0"
#define STRING_xidcontinue0 STR_x STR_i STR_d STR_c STR_o STR_n STR_t STR_i STR_n STR_u STR_e "\0"
#define STRING_xids0 STR_x STR_i STR_d STR_s "\0"
#define STRING_xidstart0 STR_x STR_i STR_d STR_s STR_t STR_a STR_r STR_t "\0"
#define STRING_xpeo0 STR_x STR_p STR_e STR_o "\0"
#define STRING_xps0 STR_x STR_p STR_s "\0"
#define STRING_xsp0 STR_x STR_s STR_p "\0"
#define STRING_xsux0 STR_x STR_s STR_u STR_x "\0"
#define STRING_xuc0 STR_x STR_u STR_c "\0"
#define STRING_xwd0 STR_x STR_w STR_d "\0"
#define STRING_yezi0 STR_y STR_e STR_z STR_i "\0"
#define STRING_yezidi0 STR_y STR_e STR_z STR_i STR_d STR_i "\0"
#define STRING_yi0 STR_y STR_i "\0"
#define STRING_yiii0 STR_y STR_i STR_i STR_i "\0"
#define STRING_z0 STR_z "\0"
#define STRING_zanabazarsquare0 STR_z STR_a STR_n STR_a STR_b STR_a STR_z STR_a STR_r STR_s STR_q STR_u STR_a STR_r STR_e "\0"
#define STRING_zanb0 STR_z STR_a STR_n STR_b "\0"
#define STRING_zinh0 STR_z STR_i STR_n STR_h "\0"
#define STRING_zl0 STR_z STR_l "\0"
#define STRING_zp0 STR_z STR_p "\0"
#define STRING_zs0 STR_z STR_s "\0"
#define STRING_zyyy0 STR_z STR_y STR_y STR_y "\0"
#define STRING_zzzz0 STR_z STR_z STR_z STR_z "\0"

const char PRIV(utt_names)[] =
  STRING_adlam0
  STRING_adlm0
  STRING_aghb0
  STRING_ahex0
  STRING_ahom0
  STRING_alpha0
  STRING_alphabetic0
  STRING_anatolianhieroglyphs0
  STRING_any0
  STRING_arab0
  STRING_arabic0
  STRING_armenian0
  STRING_armi0
  STRING_armn0
  STRING_ascii0
  STRING_asciihexdigit0
  STRING_avestan0
  STRING_avst0
  STRING_bali0
  STRING_balinese0
  STRING_bamu0
  STRING_bamum0
  STRING_bass0
  STRING_bassavah0
  STRING_batak0
  STRING_batk0
  STRING_beng0
  STRING_bengali0
  STRING_bhaiksuki0
  STRING_bhks0
  STRING_bidial0
  STRING_bidian0
  STRING_bidib0
  STRING_bidibn0
  STRING_bidic0
  STRING_bidicontrol0
  STRING_bidics0
  STRING_bidien0
  STRING_bidies0
  STRING_bidiet0
  STRING_bidifsi0
  STRING_bidil0
  STRING_bidilre0
  STRING_bidilri0
  STRING_bidilro0
  STRING_bidim0
  STRING_bidimirrored0
  STRING_bidinsm0
  STRING_bidion0
  STRING_bidipdf0
  STRING_bidipdi0
  STRING_bidir0
  STRING_bidirle0
  STRING_bidirli0
  STRING_bidirlo0
  STRING_bidis0
  STRING_bidiws0
  STRING_bopo0
  STRING_bopomofo0
  STRING_brah0
  STRING_brahmi0
  STRING_brai0
  STRING_braille0
  STRING_bugi0
  STRING_buginese0
  STRING_buhd0
  STRING_buhid0
  STRING_c0
  STRING_cakm0
  STRING_canadianaboriginal0
  STRING_cans0
  STRING_cari0
  STRING_carian0
  STRING_cased0
  STRING_cased0
  STRING_caseignorable0
  STRING_caucasianalbanian0
  STRING_cc0
  STRING_cf0
  STRING_chakma0
  STRING_cham0
  STRING_changeswhencasefolded0
  STRING_changeswhencasemapped0
  STRING_changeswhenlowercased0
  STRING_changeswhentitlecased0
  STRING_changeswhenuppercased0
  STRING_cher0
  STRING_cherokee0
  STRING_chorasmian0
  STRING_chrs0
  STRING_ci0
  STRING_cn0
  STRING_co0
  STRING_common0
  STRING_copt0
  STRING_coptic0
  STRING_cpmn0
  STRING_cprt0
  STRING_cs0
  STRING_cuneiform0
  STRING_cwcf0
  STRING_cwcm0
  STRING_cwl0
  STRING_cwt0
  STRING_cwu0
  STRING_cypriot0
  STRING_cyprominoan0
  STRING_cyrillic0
  STRING_cyrl0
  STRING_dash0
  STRING_dash0
  STRING_defaultignorablecodepoint0
  STRING_dep0
  STRING_deprecated0
  STRING_deseret0
  STRING_deva0
  STRING_devanagari0
  STRING_di0
  STRING_dia0
  STRING_diacritic0
  STRING_diak0
  STRING_divesakuru0
  STRING_dogr0
  STRING_dogra0
  STRING_dsrt0
  STRING_dupl0
  STRING_duployan0
  STRING_ebase0
  STRING_ecomp0
  STRING_egyp0
  STRING_egyptianhieroglyphs0
  STRING_elba0
  STRING_elbasan0
  STRING_elym0
  STRING_elymaic0
  STRING_emod0
  STRING_emoji0
  STRING_emoji0
  STRING_emojicomponent0
  STRING_emojimodifier0
  STRING_emojimodifierbase0
  STRING_emojipresentation0
  STRING_epres0
  STRING_ethi0
  STRING_ethiopic0
  STRING_ext0
  STRING_extendedpictographic0
  STRING_extender0
  STRING_extpict0
  STRING_geor0
  STRING_georgian0
  STRING_glag0
  STRING_glagolitic0
  STRING_gong0
  STRING_gonm0
  STRING_goth0
  STRING_gothic0
  STRING_gran0
  STRING_grantha0
  STRING_graphemebase0
  STRING_graphemeextend0
  STRING_graphemelink0
  STRING_grbase0
  STRING_greek0
  STRING_grek0
  STRING_grext0
  STRING_grlink0
  STRING_gujarati0
  STRING_gujr0
  STRING_gunjalagondi0
  STRING_gurmukhi0
  STRING_guru0
  STRING_han0
  STRING_hang0
  STRING_hangul0
  STRING_hani0
  STRING_hanifirohingya0
  STRING_hano0
  STRING_hanunoo0
  STRING_hatr0
  STRING_hatran0
  STRING_hebr0
  STRING_hebrew0
  STRING_hex0
  STRING_hexdigit0
  STRING_hira0
  STRING_hiragana0
  STRING_hluw0
  STRING_hmng0
  STRING_hmnp0
  STRING_hung0
  STRING_idc0
  STRING_idcontinue0
  STRING_ideo0
  STRING_ideographic0
  STRING_ids0
  STRING_idsb0
  STRING_idsbinaryoperator0
  STRING_idst0
  STRING_idstart0
  STRING_idstrinaryoperator0
  STRING_imperialaramaic0
  STRING_inherited0
  STRING_inscriptionalpahlavi0
  STRING_inscriptionalparthian0
  STRING_ital0
  STRING_java0
  STRING_javanese0
  STRING_joinc0
  STRING_joincontrol0
  STRING_kaithi0
  STRING_kali0
  STRING_kana0
  STRING_kannada0
  STRING_katakana0
  STRING_kayahli0
  STRING_khar0
  STRING_kharoshthi0
  STRING_khitansmallscript0
  STRING_khmer0
  STRING_khmr0
  STRING_khoj0
  STRING_khojki0
  STRING_khudawadi0
  STRING_kits0
  STRING_knda0
  STRING_kthi0
  STRING_l0
  STRING_l_AMPERSAND0
  STRING_lana0
  STRING_lao0
  STRING_laoo0
  STRING_latin0
  STRING_latn0
  STRING_lc0
  STRING_lepc0
  STRING_lepcha0
  STRING_limb0
  STRING_limbu0
  STRING_lina0
  STRING_linb0
  STRING_lineara0
  STRING_linearb0
  STRING_lisu0
  STRING_ll0
  STRING_lm0
  STRING_lo0
  STRING_loe0
  STRING_logicalorderexception0
  STRING_lower0
  STRING_lowercase0
  STRING_lt0
  STRING_lu0
  STRING_lyci0
  STRING_lycian0
  STRING_lydi0
  STRING_lydian0
  STRING_m0
  STRING_mahajani0
  STRING_mahj0
  STRING_maka0
  STRING_makasar0
  STRING_malayalam0
  STRING_mand0
  STRING_mandaic0
  STRING_mani0
  STRING_manichaean0
  STRING_marc0
  STRING_marchen0
  STRING_masaramgondi0
  STRING_math0
  STRING_math0
  STRING_mc0
  STRING_me0
  STRING_medefaidrin0
  STRING_medf0
  STRING_meeteimayek0
  STRING_mend0
  STRING_mendekikakui0
  STRING_merc0
  STRING_mero0
  STRING_meroiticcursive0
  STRING_meroitichieroglyphs0
  STRING_miao0
  STRING_mlym0
  STRING_mn0
  STRING_modi0
  STRING_mong0
  STRING_mongolian0
  STRING_mro0
  STRING_mroo0
  STRING_mtei0
  STRING_mult0
  STRING_multani0
  STRING_myanmar0
  STRING_mymr0
  STRING_n0
  STRING_nabataean0
  STRING_nand0
  STRING_nandinagari0
  STRING_narb0
  STRING_nbat0
  STRING_nchar0
  STRING_nd0
  STRING_newa0
  STRING_newtailue0
  STRING_nko0
  STRING_nkoo0
  STRING_nl0
  STRING_no0
  STRING_noncharactercodepoint0
  STRING_nshu0
  STRING_nushu0
  STRING_nyiakengpuachuehmong0
  STRING_ogam0
  STRING_ogham0
  STRING_olchiki0
  STRING_olck0
  STRING_oldhungarian0
  STRING_olditalic0
  STRING_oldnortharabian0
  STRING_oldpermic0
  STRING_oldpersian0
  STRING_oldsogdian0
  STRING_oldsoutharabian0
  STRING_oldturkic0
  STRING_olduyghur0
  STRING_oriya0
  STRING_orkh0
  STRING_orya0
  STRING_osage0
  STRING_osge0
  STRING_osma0
  STRING_osmanya0
  STRING_ougr0
  STRING_p0
  STRING_pahawhhmong0
  STRING_palm0
  STRING_palmyrene0
  STRING_patsyn0
  STRING_patternsyntax0
  STRING_patternwhitespace0
  STRING_patws0
  STRING_pauc0
  STRING_paucinhau0
  STRING_pc0
  STRING_pcm0
  STRING_pd0
  STRING_pe0
  STRING_perm0
  STRING_pf0
  STRING_phag0
  STRING_phagspa0
  STRING_phli0
  STRING_phlp0
  STRING_phnx0
  STRING_phoenician0
  STRING_pi0
  STRING_plrd0
  STRING_po0
  STRING_prependedconcatenationmark0
  STRING_prti0
  STRING_ps0
  STRING_psalterpahlavi0
  STRING_qaac0
  STRING_qaai0
  STRING_qmark0
  STRING_quotationmark0
  STRING_radical0
  STRING_radical0
  STRING_regionalindicator0
  STRING_rejang0
  STRING_ri0
  STRING_rjng0
  STRING_rohg0
  STRING_runic0
  STRING_runr0
  STRING_s0
  STRING_samaritan0
  STRING_samr0
  STRING_sarb0
  STRING_saur0
  STRING_saurashtra0
  STRING_sc0
  STRING_sd0
  STRING_sentenceterminal0
  STRING_sgnw0
  STRING_sharada0
  STRING_shavian0
  STRING_shaw0
  STRING_shrd0
  STRING_sidd0
  STRING_siddham0
  STRING_signwriting0
  STRING_sind0
  STRING_sinh0
  STRING_sinhala0
  STRING_sk0
  STRING_sm0
  STRING_so0
  STRING_softdotted0
  STRING_sogd0
  STRING_sogdian0
  STRING_sogo0
  STRING_sora0
  STRING_sorasompeng0
  STRING_soyo0
  STRING_soyombo0
  STRING_space0
  STRING_sterm0
  STRING_sund0
  STRING_sundanese0
  STRING_sylo0
  STRING_sylotinagri0
  STRING_syrc0
  STRING_syriac0
  STRING_tagalog0
  STRING_tagb0
  STRING_tagbanwa0
  STRING_taile0
  STRING_taitham0
  STRING_taiviet0
  STRING_takr0
  STRING_takri0
  STRING_tale0
  STRING_talu0
  STRING_tamil0
  STRING_taml0
  STRING_tang0
  STRING_tangsa0
  STRING_tangut0
  STRING_tavt0
  STRING_telu0
  STRING_telugu0
  STRING_term0
  STRING_terminalpunctuation0
  STRING_tfng0
  STRING_tglg0
  STRING_thaa0
  STRING_thaana0
  STRING_thai0
  STRING_tibetan0
  STRING_tibt0
  STRING_tifinagh0
  STRING_tirh0
  STRING_tirhuta0
  STRING_tnsa0
  STRING_toto0
  STRING_ugar0
  STRING_ugaritic0
  STRING_uideo0
  STRING_unifiedideograph0
  STRING_unknown0
  STRING_upper0
  STRING_uppercase0
  STRING_vai0
  STRING_vaii0
  STRING_variationselector0
  STRING_vith0
  STRING_vithkuqi0
  STRING_vs0
  STRING_wancho0
  STRING_wara0
  STRING_warangciti0
  STRING_wcho0
  STRING_whitespace0
  STRING_wspace0
  STRING_xan0
  STRING_xidc0
  STRING_xidcontinue0
  STRING_xids0
  STRING_xidstart0
  STRING_xpeo0
  STRING_xps0
  STRING_xsp0
  STRING_xsux0
  STRING_xuc0
  STRING_xwd0
  STRING_yezi0
  STRING_yezidi0
  STRING_yi0
  STRING_yiii0
  STRING_z0
  STRING_zanabazarsquare0
  STRING_zanb0
  STRING_zinh0
  STRING_zl0
  STRING_zp0
  STRING_zs0
  STRING_zyyy0
  STRING_zzzz0;

const ucp_type_table PRIV(utt)[] = {
  {   0, PT_SCX, ucp_Adlam },
  {   6, PT_SCX, ucp_Adlam },
  {  11, PT_SC, ucp_Caucasian_Albanian },
  {  16, PT_BOOL, ucp_ASCII_Hex_Digit },
  {  21, PT_SC, ucp_Ahom },
  {  26, PT_BOOL, ucp_Alphabetic },
  {  32, PT_BOOL, ucp_Alphabetic },
  {  43, PT_SC, ucp_Anatolian_Hieroglyphs },
  {  64, PT_ANY, 0 },
  {  68, PT_SCX, ucp_Arabic },
  {  73, PT_SCX, ucp_Arabic },
  {  80, PT_SC, ucp_Armenian },
  {  89, PT_SC, ucp_Imperial_Aramaic },
  {  94, PT_SC, ucp_Armenian },
  {  99, PT_BOOL, ucp_ASCII },
  { 105, PT_BOOL, ucp_ASCII_Hex_Digit },
  { 119, PT_SC, ucp_Avestan },
  { 127, PT_SC, ucp_Avestan },
  { 132, PT_SC, ucp_Balinese },
  { 137, PT_SC, ucp_Balinese },
  { 146, PT_SC, ucp_Bamum },
  { 151, PT_SC, ucp_Bamum },
  { 157, PT_SC, ucp_Bassa_Vah },
  { 162, PT_SC, ucp_Bassa_Vah },
  { 171, PT_SC, ucp_Batak },
  { 177, PT_SC, ucp_Batak },
  { 182, PT_SCX, ucp_Bengali },
  { 187, PT_SCX, ucp_Bengali },
  { 195, PT_SC, ucp_Bhaiksuki },
  { 205, PT_SC, ucp_Bhaiksuki },
  { 210, PT_BIDICL, ucp_bidiAL },
  { 217, PT_BIDICL, ucp_bidiAN },
  { 224, PT_BIDICL, ucp_bidiB },
  { 230, PT_BIDICL, ucp_bidiBN },
  { 237, PT_BOOL, ucp_Bidi_Control },
  { 243, PT_BOOL, ucp_Bidi_Control },
  { 255, PT_BIDICL, ucp_bidiCS },
  { 262, PT_BIDICL, ucp_bidiEN },
  { 269, PT_BIDICL, ucp_bidiES },
  { 276, PT_BIDICL, ucp_bidiET },
  { 283, PT_BIDICL, ucp_bidiFSI },
  { 291, PT_BIDICL, ucp_bidiL },
  { 297, PT_BIDICL, ucp_bidiLRE },
  { 305, PT_BIDICL, ucp_bidiLRI },
  { 313, PT_BIDICL, ucp_bidiLRO },
  { 321, PT_BOOL, ucp_Bidi_Mirrored },
  { 327, PT_BOOL, ucp_Bidi_Mirrored },
  { 340, PT_BIDICL, ucp_bidiNSM },
  { 348, PT_BIDICL, ucp_bidiON },
  { 355, PT_BIDICL, ucp_bidiPDF },
  { 363, PT_BIDICL, ucp_bidiPDI },
  { 371, PT_BIDICL, ucp_bidiR },
  { 377, PT_BIDICL, ucp_bidiRLE },
  { 385, PT_BIDICL, ucp_bidiRLI },
  { 393, PT_BIDICL, ucp_bidiRLO },
  { 401, PT_BIDICL, ucp_bidiS },
  { 407, PT_BIDICL, ucp_bidiWS },
  { 414, PT_SCX, ucp_Bopomofo },
  { 419, PT_SCX, ucp_Bopomofo },
  { 428, PT_SC, ucp_Brahmi },
  { 433, PT_SC, ucp_Brahmi },
  { 440, PT_SC, ucp_Braille },
  { 445, PT_SC, ucp_Braille },
  { 453, PT_SCX, ucp_Buginese },
  { 458, PT_SCX, ucp_Buginese },
  { 467, PT_SCX, ucp_Buhid },
  { 472, PT_SCX, ucp_Buhid },
  { 478, PT_GC, ucp_C },
  { 480, PT_SCX, ucp_Chakma },
  { 485, PT_SC, ucp_Canadian_Aboriginal },
  { 504, PT_SC, ucp_Canadian_Aboriginal },
  { 509, PT_SC, ucp_Carian },
  { 514, PT_SC, ucp_Carian },
  { 521, PT_BOOL, ucp_Cased },
  { 527, PT_BOOL, ucp_Cased },
  { 533, PT_BOOL, ucp_Case_Ignorable },
  { 547, PT_SC, ucp_Caucasian_Albanian },
  { 565, PT_PC, ucp_Cc },
  { 568, PT_PC, ucp_Cf },
  { 571, PT_SCX, ucp_Chakma },
  { 578, PT_SC, ucp_Cham },
  { 583, PT_BOOL, ucp_Changes_When_Casefolded },
  { 605, PT_BOOL, ucp_Changes_When_Casemapped },
  { 627, PT_BOOL, ucp_Changes_When_Lowercased },
  { 649, PT_BOOL, ucp_Changes_When_Titlecased },
  { 671, PT_BOOL, ucp_Changes_When_Uppercased },
  { 693, PT_SC, ucp_Cherokee },
  { 698, PT_SC, ucp_Cherokee },
  { 707, PT_SC, ucp_Chorasmian },
  { 718, PT_SC, ucp_Chorasmian },
  { 723, PT_BOOL, ucp_Case_Ignorable },
  { 726, PT_PC, ucp_Cn },
  { 729, PT_PC, ucp_Co },
  { 732, PT_SC, ucp_Common },
  { 739, PT_SCX, ucp_Coptic },
  { 744, PT_SCX, ucp_Coptic },
  { 751, PT_SCX, ucp_Cypro_Minoan },
  { 756, PT_SCX, ucp_Cypriot },
  { 761, PT_PC, ucp_Cs },
  { 764, PT_SC, ucp_Cuneiform },
  { 774, PT_BOOL, ucp_Changes_When_Casefolded },
  { 779, PT_BOOL, ucp_Changes_When_Casemapped },
  { 784, PT_BOOL, ucp_Changes_When_Lowercased },
  { 788, PT_BOOL, ucp_Changes_When_Titlecased },
  { 792, PT_BOOL, ucp_Changes_When_Uppercased },
  { 796, PT_SCX, ucp_Cypriot },
  { 804, PT_SCX, ucp_Cypro_Minoan },
  { 816, PT_SCX, ucp_Cyrillic },
  { 825, PT_SCX, ucp_Cyrillic },
  { 830, PT_BOOL, ucp_Dash },
  { 835, PT_BOOL, ucp_Dash },
  { 840, PT_BOOL, ucp_Default_Ignorable_Code_Point },
  { 866, PT_BOOL, ucp_Deprecated },
  { 870, PT_BOOL, ucp_Deprecated },
  { 881, PT_SC, ucp_Deseret },
  { 889, PT_SCX, ucp_Devanagari },
  { 894, PT_SCX, ucp_Devanagari },
  { 905, PT_BOOL, ucp_Default_Ignorable_Code_Point },
  { 908, PT_BOOL, ucp_Diacritic },
  { 912, PT_BOOL, ucp_Diacritic },
  { 922, PT_SC, ucp_Dives_Akuru },
  { 927, PT_SC, ucp_Dives_Akuru },
  { 938, PT_SCX, ucp_Dogra },
  { 943, PT_SCX, ucp_Dogra },
  { 949, PT_SC, ucp_Deseret },
  { 954, PT_SCX, ucp_Duployan },
  { 959, PT_SCX, ucp_Duployan },
  { 968, PT_BOOL, ucp_Emoji_Modifier_Base },
  { 974, PT_BOOL, ucp_Emoji_Component },
  { 980, PT_SC, ucp_Egyptian_Hieroglyphs },
  { 985, PT_SC, ucp_Egyptian_Hieroglyphs },
  { 1005, PT_SC, ucp_Elbasan },
  { 1010, PT_SC, ucp_Elbasan },
  { 1018, PT_SC, ucp_Elymaic },
  { 1023, PT_SC, ucp_Elymaic },
  { 1031, PT_BOOL, ucp_Emoji_Modifier },
  { 1036, PT_BOOL, ucp_Emoji },
  { 1042, PT_BOOL, ucp_Emoji },
  { 1048, PT_BOOL, ucp_Emoji_Component },
  { 1063, PT_BOOL, ucp_Emoji_Modifier },
  { 1077, PT_BOOL, ucp_Emoji_Modifier_Base },
  { 1095, PT_BOOL, ucp_Emoji_Presentation },
  { 1113, PT_BOOL, ucp_Emoji_Presentation },
  { 1119, PT_SC, ucp_Ethiopic },
  { 1124, PT_SC, ucp_Ethiopic },
  { 1133, PT_BOOL, ucp_Extender },
  { 1137, PT_BOOL, ucp_Extended_Pictographic },
  { 1158, PT_BOOL, ucp_Extender },
  { 1167, PT_BOOL, ucp_Extended_Pictographic },
  { 1175, PT_SCX, ucp_Georgian },
  { 1180, PT_SCX, ucp_Georgian },
  { 1189, PT_SCX, ucp_Glagolitic },
  { 1194, PT_SCX, ucp_Glagolitic },
  { 1205, PT_SCX, ucp_Gunjala_Gondi },
  { 1210, PT_SCX, ucp_Masaram_Gondi },
  { 1215, PT_SC, ucp_Gothic },
  { 1220, PT_SC, ucp_Gothic },
  { 1227, PT_SCX, ucp_Grantha },
  { 1232, PT_SCX, ucp_Grantha },
  { 1240, PT_BOOL, ucp_Grapheme_Base },
  { 1253, PT_BOOL, ucp_Grapheme_Extend },
  { 1268, PT_BOOL, ucp_Grapheme_Link },
  { 1281, PT_BOOL, ucp_Grapheme_Base },
  { 1288, PT_SCX, ucp_Greek },
  { 1294, PT_SCX, ucp_Greek },
  { 1299, PT_BOOL, ucp_Grapheme_Extend },
  { 1305, PT_BOOL, ucp_Grapheme_Link },
  { 1312, PT_SCX, ucp_Gujarati },
  { 1321, PT_SCX, ucp_Gujarati },
  { 1326, PT_SCX, ucp_Gunjala_Gondi },
  { 1339, PT_SCX, ucp_Gurmukhi },
  { 1348, PT_SCX, ucp_Gurmukhi },
  { 1353, PT_SCX, ucp_Han },
  { 1357, PT_SCX, ucp_Hangul },
  { 1362, PT_SCX, ucp_Hangul },
  { 1369, PT_SCX, ucp_Han },
  { 1374, PT_SCX, ucp_Hanifi_Rohingya },
  { 1389, PT_SCX, ucp_Hanunoo },
  { 1394, PT_SCX, ucp_Hanunoo },
  { 1402, PT_SC, ucp_Hatran },
  { 1407, PT_SC, ucp_Hatran },
  { 1414, PT_SC, ucp_Hebrew },
  { 1419, PT_SC, ucp_Hebrew },
  { 1426, PT_BOOL, ucp_Hex_Digit },
  { 1430, PT_BOOL, ucp_Hex_Digit },
  { 1439, PT_SCX, ucp_Hiragana },
  { 1444, PT_SCX, ucp_Hiragana },
  { 1453, PT_SC, ucp_Anatolian_Hieroglyphs },
  { 1458, PT_SC, ucp_Pahawh_Hmong },
  { 1463, PT_SC, ucp_Nyiakeng_Puachue_Hmong },
  { 1468, PT_SC, ucp_Old_Hungarian },
  { 1473, PT_BOOL, ucp_ID_Continue },
  { 1477, PT_BOOL, ucp_ID_Continue },
  { 1488, PT_BOOL, ucp_Ideographic },
  { 1493, PT_BOOL, ucp_Ideographic },
  { 1505, PT_BOOL, ucp_ID_Start },
  { 1509, PT_BOOL, ucp_IDS_Binary_Operator },
  { 1514, PT_BOOL, ucp_IDS_Binary_Operator },
  { 1532, PT_BOOL, ucp_IDS_Trinary_Operator },
  { 1537, PT_BOOL, ucp_ID_Start },
  { 1545, PT_BOOL, ucp_IDS_Trinary_Operator },
  { 1564, PT_SC, ucp_Imperial_Aramaic },
  { 1580, PT_SC, ucp_Inherited },
  { 1590, PT_SC, ucp_Inscriptional_Pahlavi },
  { 1611, PT_SC, ucp_Inscriptional_Parthian },
  { 1633, PT_SC, ucp_Old_Italic },
  { 1638, PT_SCX, ucp_Javanese },
  { 1643, PT_SCX, ucp_Javanese },
  { 1652, PT_BOOL, ucp_Join_Control },
  { 1658, PT_BOOL, ucp_Join_Control },
  { 1670, PT_SCX, ucp_Kaithi },
  { 1677, PT_SCX, ucp_Kayah_Li },
  { 1682, PT_SCX, ucp_Katakana },
  { 1687, PT_SCX, ucp_Kannada },
  { 1695, PT_SCX, ucp_Katakana },
  { 1704, PT_SCX, ucp_Kayah_Li },
  { 1712, PT_SC, ucp_Kharoshthi },
  { 1717, PT_SC, ucp_Kharoshthi },
  { 1728, PT_SC, ucp_Khitan_Small_Script },
  { 1746, PT_SC, ucp_Khmer },
  { 1752, PT_SC, ucp_Khmer },
  { 1757, PT_SCX, ucp_Khojki },
  { 1762, PT_SCX, ucp_Khojki },
  { 1769, PT_SCX, ucp_Khudawadi },
  { 1779, PT_SC, ucp_Khitan_Small_Script },
  { 1784, PT_SCX, ucp_Kannada },
  { 1789, PT_SCX, ucp_Kaithi },
  { 1794, PT_GC, ucp_L },
  { 1796, PT_LAMP, 0 },
  { 1799, PT_SC, ucp_Tai_Tham },
  { 1804, PT_SC, ucp_Lao },
  { 1808, PT_SC, ucp_Lao },
  { 1813, PT_SCX, ucp_Latin },
  { 1819, PT_SCX, ucp_Latin },
  { 1824, PT_LAMP, 0 },
  { 1827, PT_SC, ucp_Lepcha },
  { 1832, PT_SC, ucp_Lepcha },
  { 1839, PT_SCX, ucp_Limbu },
  { 1844, PT_SCX, ucp_Limbu },
  { 1850, PT_SCX, ucp_Linear_A },
  { 1855, PT_SCX, ucp_Linear_B },
  { 1860, PT_SCX, ucp_Linear_A },
  { 1868, PT_SCX, ucp_Linear_B },
  { 1876, PT_SC, ucp_Lisu },
  { 1881, PT_PC, ucp_Ll },
  { 1884, PT_PC, ucp_Lm },
  { 1887, PT_PC, ucp_Lo },
  { 1890, PT_BOOL, ucp_Logical_Order_Exception },
  { 1894, PT_BOOL, ucp_Logical_Order_Exception },
  { 1916, PT_BOOL, ucp_Lowercase },
  { 1922, PT_BOOL, ucp_Lowercase },
  { 1932, PT_PC, ucp_Lt },
  { 1935, PT_PC, ucp_Lu },
  { 1938, PT_SC, ucp_Lycian },
  { 1943, PT_SC, ucp_Lycian },
  { 1950, PT_SC, ucp_Lydian },
  { 1955, PT_SC, ucp_Lydian },
  { 1962, PT_GC, ucp_M },
  { 1964, PT_SCX, ucp_Mahajani },
  { 1973, PT_SCX, ucp_Mahajani },
  { 1978, PT_SC, ucp_Makasar },
  { 1983, PT_SC, ucp_Makasar },
  { 1991, PT_SCX, ucp_Malayalam },
  { 2001, PT_SCX, ucp_Mandaic },
  { 2006, PT_SCX, ucp_Mandaic },
  { 2014, PT_SCX, ucp_Manichaean },
  { 2019, PT_SCX, ucp_Manichaean },
  { 2030, PT_SC, ucp_Marchen },
  { 2035, PT_SC, ucp_Marchen },
  { 2043, PT_SCX, ucp_Masaram_Gondi },
  { 2056, PT_BOOL, ucp_Math },
  { 2061, PT_BOOL, ucp_Math },
  { 2066, PT_PC, ucp_Mc },
  { 2069, PT_PC, ucp_Me },
  { 2072, PT_SC, ucp_Medefaidrin },
  { 2084, PT_SC, ucp_Medefaidrin },
  { 2089, PT_SC, ucp_Meetei_Mayek },
  { 2101, PT_SC, ucp_Mende_Kikakui },
  { 2106, PT_SC, ucp_Mende_Kikakui },
  { 2119, PT_SC, ucp_Meroitic_Cursive },
  { 2124, PT_SC, ucp_Meroitic_Hieroglyphs },
  { 2129, PT_SC, ucp_Meroitic_Cursive },
  { 2145, PT_SC, ucp_Meroitic_Hieroglyphs },
  { 2165, PT_SC, ucp_Miao },
  { 2170, PT_SCX, ucp_Malayalam },
  { 2175, PT_PC, ucp_Mn },
  { 2178, PT_SCX, ucp_Modi },
  { 2183, PT_SCX, ucp_Mongolian },
  { 2188, PT_SCX, ucp_Mongolian },
  { 2198, PT_SC, ucp_Mro },
  { 2202, PT_SC, ucp_Mro },
  { 2207, PT_SC, ucp_Meetei_Mayek },
  { 2212, PT_SCX, ucp_Multani },
  { 2217, PT_SCX, ucp_Multani },
  { 2225, PT_SCX, ucp_Myanmar },
  { 2233, PT_SCX, ucp_Myanmar },
  { 2238, PT_GC, ucp_N },
  { 2240, PT_SC, ucp_Nabataean },
  { 2250, PT_SCX, ucp_Nandinagari },
  { 2255, PT_SCX, ucp_Nandinagari },
  { 2267, PT_SC, ucp_Old_North_Arabian },
  { 2272, PT_SC, ucp_Nabataean },
  { 2277, PT_BOOL, ucp_Noncharacter_Code_Point },
  { 2283, PT_PC, ucp_Nd },
  { 2286, PT_SC, ucp_Newa },
  { 2291, PT_SC, ucp_New_Tai_Lue },
  { 2301, PT_SCX, ucp_Nko },
  { 2305, PT_SCX, ucp_Nko },
  { 2310, PT_PC, ucp_Nl },
  { 2313, PT_PC, ucp_No },
  { 2316, PT_BOOL, ucp_Noncharacter_Code_Point },
  { 2338, PT_SC, ucp_Nushu },
  { 2343, PT_SC, ucp_Nushu },
  { 2349, PT_SC, ucp_Nyiakeng_Puachue_Hmong },
  { 2370, PT_SC, ucp_Ogham },
  { 2375, PT_SC, ucp_Ogham },
  { 2381, PT_SC, ucp_Ol_Chiki },
  { 2389, PT_SC, ucp_Ol_Chiki },
  { 2394, PT_SC, ucp_Old_Hungarian },
  { 2407, PT_SC, ucp_Old_Italic },
  { 2417, PT_SC, ucp_Old_North_Arabian },
  { 2433, PT_SCX, ucp_Old_Permic },
  { 2443, PT_SC, ucp_Old_Persian },
  { 2454, PT_SC, ucp_Old_Sogdian },
  { 2465, PT_SC, ucp_Old_South_Arabian },
  { 2481, PT_SC, ucp_Old_Turkic },
  { 2491, PT_SCX, ucp_Old_Uyghur },
  { 2501, PT_SCX, ucp_Oriya },
  { 2507, PT_SC, ucp_Old_Turkic },
  { 2512, PT_SCX, ucp_Oriya },
  { 2517, PT_SC, ucp_Osage },
  { 2523, PT_SC, ucp_Osage },
  { 2528, PT_SC, ucp_Osmanya },
  { 2533, PT_SC, ucp_Osmanya },
  { 2541, PT_SCX, ucp_Old_Uyghur },
  { 2546, PT_GC, ucp_P },
  { 2548, PT_SC, ucp_Pahawh_Hmong },
  { 2560, PT_SC, ucp_Palmyrene },
  { 2565, PT_SC, ucp_Palmyrene },
  { 2575, PT_BOOL, ucp_Pattern_Syntax },
  { 2582, PT_BOOL, ucp_Pattern_Syntax },
  { 2596, PT_BOOL, ucp_Pattern_White_Space },
  { 2614, PT_BOOL, ucp_Pattern_White_Space },
  { 2620, PT_SC, ucp_Pau_Cin_Hau },
  { 2625, PT_SC, ucp_Pau_Cin_Hau },
  { 2635, PT_PC, ucp_Pc },
  { 2638, PT_BOOL, ucp_Prepended_Concatenation_Mark },
  { 2642, PT_PC, ucp_Pd },
  { 2645, PT_PC, ucp_Pe },
  { 2648, PT_SCX, ucp_Old_Permic },
  { 2653, PT_PC, ucp_Pf },
  { 2656, PT_SCX, ucp_Phags_Pa },
  { 2661, PT_SCX, ucp_Phags_Pa },
  { 2669, PT_SC, ucp_Inscriptional_Pahlavi },
  { 2674, PT_SCX, ucp_Psalter_Pahlavi },
  { 2679, PT_SC, ucp_Phoenician },
  { 2684, PT_SC, ucp_Phoenician },
  { 2695, PT_PC, ucp_Pi },
  { 2698, PT_SC, ucp_Miao },
  { 2703, PT_PC, ucp_Po },
  { 2706, PT_BOOL, ucp_Prepended_Concatenation_Mark },
  { 2733, PT_SC, ucp_Inscriptional_Parthian },
  { 2738, PT_PC, ucp_Ps },
  { 2741, PT_SCX, ucp_Psalter_Pahlavi },
  { 2756, PT_SCX, ucp_Coptic },
  { 2761, PT_SC, ucp_Inherited },
  { 2766, PT_BOOL, ucp_Quotation_Mark },
  { 2772, PT_BOOL, ucp_Quotation_Mark },
  { 2786, PT_BOOL, ucp_Radical },
  { 2794, PT_BOOL, ucp_Radical },
  { 2802, PT_BOOL, ucp_Regional_Indicator },
  { 2820, PT_SC, ucp_Rejang },
  { 2827, PT_BOOL, ucp_Regional_Indicator },
  { 2830, PT_SC, ucp_Rejang },
  { 2835, PT_SCX, ucp_Hanifi_Rohingya },
  { 2840, PT_SC, ucp_Runic },
  { 2846, PT_SC, ucp_Runic },
  { 2851, PT_GC, ucp_S },
  { 2853, PT_SC, ucp_Samaritan },
  { 2863, PT_SC, ucp_Samaritan },
  { 2868, PT_SC, ucp_Old_South_Arabian },
  { 2873, PT_SC, ucp_Saurashtra },
  { 2878, PT_SC, ucp_Saurashtra },
  { 2889, PT_PC, ucp_Sc },
  { 2892, PT_BOOL, ucp_Soft_Dotted },
  { 2895, PT_BOOL, ucp_Sentence_Terminal },
  { 2912, PT_SC, ucp_SignWriting },
  { 2917, PT_SCX, ucp_Sharada },
  { 2925, PT_SC, ucp_Shavian },
  { 2933, PT_SC, ucp_Shavian },
  { 2938, PT_SCX, ucp_Sharada },
  { 2943, PT_SC, ucp_Siddham },
  { 2948, PT_SC, ucp_Siddham },
  { 2956, PT_SC, ucp_SignWriting },
  { 2968, PT_SCX, ucp_Khudawadi },
  { 2973, PT_SCX, ucp_Sinhala },
  { 2978, PT_SCX, ucp_Sinhala },
  { 2986, PT_PC, ucp_Sk },
  { 2989, PT_PC, ucp_Sm },
  { 2992, PT_PC, ucp_So },
  { 2995, PT_BOOL, ucp_Soft_Dotted },
  { 3006, PT_SCX, ucp_Sogdian },
  { 3011, PT_SCX, ucp_Sogdian },
  { 3019, PT_SC, ucp_Old_Sogdian },
  { 3024, PT_SC, ucp_Sora_Sompeng },
  { 3029, PT_SC, ucp_Sora_Sompeng },
  { 3041, PT_SC, ucp_Soyombo },
  { 3046, PT_SC, ucp_Soyombo },
  { 3054, PT_BOOL, ucp_White_Space },
  { 3060, PT_BOOL, ucp_Sentence_Terminal },
  { 3066, PT_SC, ucp_Sundanese },
  { 3071, PT_SC, ucp_Sundanese },
  { 3081, PT_SCX, ucp_Syloti_Nagri },
  { 3086, PT_SCX, ucp_Syloti_Nagri },
  { 3098, PT_SCX, ucp_Syriac },
  { 3103, PT_SCX, ucp_Syriac },
  { 3110, PT_SCX, ucp_Tagalog },
  { 3118, PT_SCX, ucp_Tagbanwa },
  { 3123, PT_SCX, ucp_Tagbanwa },
  { 3132, PT_SCX, ucp_Tai_Le },
  { 3138, PT_SC, ucp_Tai_Tham },
  { 3146, PT_SC, ucp_Tai_Viet },
  { 3154, PT_SCX, ucp_Takri },
  { 3159, PT_SCX, ucp_Takri },
  { 3165, PT_SCX, ucp_Tai_Le },
  { 3170, PT_SC, ucp_New_Tai_Lue },
  { 3175, PT_SCX, ucp_Tamil },
  { 3181, PT_SCX, ucp_Tamil },
  { 3186, PT_SC, ucp_Tangut },
  { 3191, PT_SC, ucp_Tangsa },
  { 3198, PT_SC, ucp_Tangut },
  { 3205, PT_SC, ucp_Tai_Viet },
  { 3210, PT_SCX, ucp_Telugu },
  { 3215, PT_SCX, ucp_Telugu },
  { 3222, PT_BOOL, ucp_Terminal_Punctuation },
  { 3227, PT_BOOL, ucp_Terminal_Punctuation },
  { 3247, PT_SC, ucp_Tifinagh },
  { 3252, PT_SCX, ucp_Tagalog },
  { 3257, PT_SCX, ucp_Thaana },
  { 3262, PT_SCX, ucp_Thaana },
  { 3269, PT_SC, ucp_Thai },
  { 3274, PT_SC, ucp_Tibetan },
  { 3282, PT_SC, ucp_Tibetan },
  { 3287, PT_SC, ucp_Tifinagh },
  { 3296, PT_SCX, ucp_Tirhuta },
  { 3301, PT_SCX, ucp_Tirhuta },
  { 3309, PT_SC, ucp_Tangsa },
  { 3314, PT_SC, ucp_Toto },
  { 3319, PT_SC, ucp_Ugaritic },
  { 3324, PT_SC, ucp_Ugaritic },
  { 3333, PT_BOOL, ucp_Unified_Ideograph },
  { 3339, PT_BOOL, ucp_Unified_Ideograph },
  { 3356, PT_SC, ucp_Unknown },
  { 3364, PT_BOOL, ucp_Uppercase },
  { 3370, PT_BOOL, ucp_Uppercase },
  { 3380, PT_SC, ucp_Vai },
  { 3384, PT_SC, ucp_Vai },
  { 3389, PT_BOOL, ucp_Variation_Selector },
  { 3407, PT_SC, ucp_Vithkuqi },
  { 3412, PT_SC, ucp_Vithkuqi },
  { 3421, PT_BOOL, ucp_Variation_Selector },
  { 3424, PT_SC, ucp_Wancho },
  { 3431, PT_SC, ucp_Warang_Citi },
  { 3436, PT_SC, ucp_Warang_Citi },
  { 3447, PT_SC, ucp_Wancho },
  { 3452, PT_BOOL, ucp_White_Space },
  { 3463, PT_BOOL, ucp_White_Space },
  { 3470, PT_ALNUM, 0 },
  { 3474, PT_BOOL, ucp_XID_Continue },
  { 3479, PT_BOOL, ucp_XID_Continue },
  { 3491, PT_BOOL, ucp_XID_Start },
  { 3496, PT_BOOL, ucp_XID_Start },
  { 3505, PT_SC, ucp_Old_Persian },
  { 3510, PT_PXSPACE, 0 },
  { 3514, PT_SPACE, 0 },
  { 3518, PT_SC, ucp_Cuneiform },
  { 3523, PT_UCNC, 0 },
  { 3527, PT_WORD, 0 },
  { 3531, PT_SCX, ucp_Yezidi },
  { 3536, PT_SCX, ucp_Yezidi },
  { 3543, PT_SCX, ucp_Yi },
  { 3546, PT_SCX, ucp_Yi },
  { 3551, PT_GC, ucp_Z },
  { 3553, PT_SC, ucp_Zanabazar_Square },
  { 3569, PT_SC, ucp_Zanabazar_Square },
  { 3574, PT_SC, ucp_Inherited },
  { 3579, PT_PC, ucp_Zl },
  { 3582, PT_PC, ucp_Zp },
  { 3585, PT_PC, ucp_Zs },
  { 3588, PT_SC, ucp_Common },
  { 3593, PT_SC, ucp_Unknown }
};

const size_t PRIV(utt_size) = sizeof(PRIV(utt)) / sizeof(ucp_type_table);

#endif /* SUPPORT_UNICODE */

/* End of pcre2_ucptables.c */
