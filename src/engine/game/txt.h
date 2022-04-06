//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================
#ifndef TXT_H
#define TXT_H
//==============================================================================


typedef struct
{
	int screen_x;//0
	int screen_y;//0

	bool activated;//0

	int line;//0
	int tile;//0
	int chunk;//0
	int x_in_tile;//0

	NPC* sprite_window_npc;//&main_npc

	SPRITE* sprite_window_sprite;
	GFX* sprite_window_gfx;

	SPRITE* chunk_sprite[3];
	SPRITE* button_sprite;

	int* indexed_gfx_data;//NULL
	int* sprite_window_indexed_gfx_data;//NULL

	int voice_pitch;//40000

	int sprite_window_top_pixel;//32

	bool redraw;

	//int shake_amount;//0;


}TEXTBOX;



//================
//variables
//================

extern int GLOBAL_text_engine_state;


extern int* FONT_NORMAL_indexed_gfx_data;
extern int* FONT_HUGE_indexed_gfx_data;
extern int* FONT_SMALL_indexed_gfx_data;
extern int* FONT_TINY_indexed_gfx_data;
extern int* FONT_OUTLINED_indexed_gfx_data;
extern int* FONT_BOB_indexed_gfx_data;
extern int* FONT_JAPANESE_indexed_gfx_data;


extern TEXTBOX TEXT_textbox[2];


extern NPC* TEXT_npc_1;
extern NPC* TEXT_npc_2;
extern NPC* TEXT_npc_3;
extern NPC* TEXT_npc_4;
extern NPC* TEXT_npc_5;
extern NPC* TEXT_npc_6;


extern int* TEXT_font_pointer;
extern int TEXT_font_id;

extern int TEXT_color[3];

extern int TEXT_font_height;

extern int TEXT_string_position;
extern int TEXT_length;

//================
//prototypes
//================


void TEXT_set_sprite_window(int box, NPC* npc, GFX* name);
void TEXT_window(const char *);

void TEXT_vbl();
void TEXT_init();

void TEXT_main();
void TEXT_update_textbox_sprite_textures();
void TEXT_draw_letter();
void TEXT_draw_column(int letter_index,int x_in_letter,int blank);
void TEXT_clear_text_box_gfx_data(int box);
void TEXT_draw_pixel(int position,int value);
void TEXT_parse_options();
void TEXT_check_next_word_length(char* text);
void TEXT_move_sprites();
void TEXT_move_up_sprite_gfx();

int font_index(char c);
int TEXT_get_char_width(int letter_index);



//================
//defines
//================


//=========================================================================================================================
//	 FONT DEFINES
//=========================================================================================================================


#define FONT_NORMAL_HEIGHT		10
#define FONT_HUGE_HEIGHT		12
#define FONT_SMALL_HEIGHT		9
#define FONT_OUTLINED_HEIGHT	10
#define FONT_TINY_HEIGHT		7
#define FONT_BOB_HEIGHT			12
#define FONT_JAPANESE_HEIGHT	12

#define FONT_NORMAL_ID		0
#define FONT_HUGE_ID			1
#define FONT_SMALL_ID		2
#define FONT_OUTLINED_ID	 3
#define FONT_TINY_ID	 		4
#define FONT_BOB_ID	 		5
#define FONT_JAPANESE_ID 	6

//=========================================================================================================================
//	 CHAR DEFINES
//=========================================================================================================================

#define CHAR_A							0
#define CHAR_B							1
#define CHAR_C							2
#define CHAR_D							3
#define CHAR_E							4
#define CHAR_F							5
#define CHAR_G							6
#define CHAR_H							7
#define CHAR_I							8
#define CHAR_J							9
#define CHAR_K							10
#define CHAR_L							11
#define CHAR_M							12
#define CHAR_N							13
#define CHAR_O							14
#define CHAR_P							15
#define CHAR_Q							16
#define CHAR_R							17
#define CHAR_S							18
#define CHAR_T							19
#define CHAR_U							20
#define CHAR_V							21
#define CHAR_W							22
#define CHAR_X							23
#define CHAR_Y							24
#define CHAR_Z							25
#define CHAR_a							26
#define CHAR_b							27
#define CHAR_c							28
#define CHAR_d							29
#define CHAR_e							30
#define CHAR_f							31
#define CHAR_g							32
#define CHAR_h							33
#define CHAR_i							34
#define CHAR_j							35
#define CHAR_k							36
#define CHAR_l							37
#define CHAR_m							38
#define CHAR_n							39
#define CHAR_o							40
#define CHAR_p							41
#define CHAR_q							42
#define CHAR_r							43
#define CHAR_s							44
#define CHAR_t							45
#define CHAR_u							46
#define CHAR_v							47
#define CHAR_w							48
#define CHAR_x							49
#define CHAR_y							50
#define CHAR_z							51
#define CHAR_0							52
#define CHAR_1							53
#define CHAR_2							54
#define CHAR_3							55
#define CHAR_4							56
#define CHAR_5							57
#define CHAR_6							58
#define CHAR_7							59
#define CHAR_8							60
#define CHAR_9							61
#define CHAR_EXCLAMATION			62
#define CHAR_QUESTIONMARK			63
#define CHAR_PERIOD					64
#define CHAR_COMMA					65
#define CHAR_QUOTE					66
#define CHAR_DOUBLEQUOTE			67
#define CHAR_COLON					68
#define CHAR_SEMICOLON				69
#define CHAR_FRONTSLASH				70
#define CHAR_BACKSLASH				71
#define CHAR_ASTERISK				72
#define CHAR_PLUS						73
#define CHAR_MINUS					74
#define CHAR_EQUALS					75
#define CHAR_UNDERSCORE				76
#define CHAR_CARET					77
#define CHAR_BACKQUOTE				78
#define CHAR_TILDE					79
#define CHAR_OPENPARENTHESIS		80
#define CHAR_CLOSEPARENTHESIS		81
#define CHAR_OPENANGLEBRACKET		82
#define CHAR_CLOSEANGLEBRACKET	83
#define CHAR_OPENCURLYBRACKET		84
#define CHAR_CLOSECURLYBRACKET	85
#define CHAR_OPENSQUAREBRACKET	86
#define CHAR_CLOSESQUAREBRACKET	87
#define CHAR_PIPE						88
#define CHAR_AT						89
#define CHAR_POUND					90
#define CHAR_DOLLAR					91
#define CHAR_PERCENT					92
#define CHAR_AMPERSAND				93
#define CHAR_BLOCK					94
#define CHAR_SPACE					95

//spanish
#define CHAR_dN		96
#define CHAR_aa		97
#define CHAR_ae		98
#define CHAR_ai		99
#define CHAR_ao		100
#define CHAR_au		101
#define CHAR_dn		102
#define CHAR_iE		103
#define CHAR_iQ		104
#define CHAR_aE		105
#define CHAR_aI		106
#define CHAR_aA		107

//Ñ
//á
//é
//í
//ó
//ú
//ñ
//¡
//¿
//É
//Í
//Á



//french
#define CHAR_RR		108
#define CHAR_LL		109
#define CHAR_ca		110
#define CHAR_ce		111
#define CHAR_ci		112
#define CHAR_co		113
#define CHAR_cu		114
#define CHAR_ga		115
#define CHAR_ge		116
#define CHAR_de		117
#define CHAR_cc		118
#define CHAR_lo		119

#define CHAR_aO		120
#define CHAR_gu		121


//»
//«
//â
//ê
//î
//ô
//û
//à
//è
//ë
//ç
//œ

//Ó
//ù


#define CHAR_dI		122
#define CHAR_dA		123
#define CHAR_dO		124
#define CHAR_dU		125
#define CHAR_da		126
#define CHAR_do		127
#define CHAR_du		128
#define CHAR_dB		129

//Ï
//Ä
//Ö
//Ü
//ä
//ö
//ü
//ß









#define KATAKANA_a							0
#define KATAKANA_i							1
#define KATAKANA_u							2
#define KATAKANA_e							3
#define KATAKANA_o							4
#define KATAKANA_ka							5
#define KATAKANA_ga							6
#define KATAKANA_ki							7
#define KATAKANA_gi							8
#define KATAKANA_ku							9
#define KATAKANA_gu							10
#define KATAKANA_ke							11
#define KATAKANA_ge							12
#define KATAKANA_ko							13
#define KATAKANA_go							14
#define KATAKANA_sa							15
#define KATAKANA_za							16
#define KATAKANA_shi							17
#define KATAKANA_ji							18
#define KATAKANA_su							19
#define KATAKANA_zu							20
#define KATAKANA_se							21
#define KATAKANA_ze							22
#define KATAKANA_so							23
#define KATAKANA_zo							24
#define KATAKANA_ta							25
#define KATAKANA_da							26
#define KATAKANA_chi							27
#define KATAKANA_di							28
#define KATAKANA_tsu							29
#define KATAKANA_du							30
#define KATAKANA_te							31
#define KATAKANA_to							32
#define KATAKANA_do							33
#define KATAKANA_na							34
#define KATAKANA_ni							35
#define KATAKANA_nu							36
#define KATAKANA_ne							37
#define KATAKANA_no							38
#define KATAKANA_ha							39
#define KATAKANA_ba							40
#define KATAKANA_pa							41
#define KATAKANA_hi							42
#define KATAKANA_bi							43
#define KATAKANA_pi							44
#define KATAKANA_fu							45
#define KATAKANA_bu							46
#define KATAKANA_pu							47
#define KATAKANA_he							48
#define KATAKANA_be							49
#define KATAKANA_pe							50
#define KATAKANA_ho							51
#define KATAKANA_bo							52
#define KATAKANA_po							53
#define KATAKANA_ma							54
#define KATAKANA_mi							55
#define KATAKANA_mu							56
#define KATAKANA_me							57
#define KATAKANA_mo							58
#define KATAKANA_ya							59
#define KATAKANA_yu							60
#define KATAKANA_yo							61
#define KATAKANA_ra							62
#define KATAKANA_ri							63
#define KATAKANA_ru							64
#define KATAKANA_re							65
#define KATAKANA_ro							66
#define KATAKANA_wa							67
#define KATAKANA_wi							68
#define KATAKANA_we							69
#define KATAKANA_wo							70
#define KATAKANA_n							71
#define KATAKANA_vu							72
#define KATAKANA_va							73
#define KATAKANA_vi							74
#define KATAKANA_ve							75
#define KATAKANA_vo							76
#define KATAKANA_iteration					79
#define KATAKANA_voiced_iteration		80
#define HIRIGANA_a							81
#define HIRIGANA_i							82
#define HIRIGANA_u							83
#define HIRIGANA_e							84
#define HIRIGANA_o							85
#define HIRIGANA_ka							86
#define HIRIGANA_ga							87
#define HIRIGANA_ki							88
#define HIRIGANA_gi							89
#define HIRIGANA_ku							90
#define HIRIGANA_gu							91
#define HIRIGANA_ke							92
#define HIRIGANA_ge							93
#define HIRIGANA_ko							94
#define HIRIGANA_go							95
#define HIRIGANA_sa							96
#define HIRIGANA_za							97
#define HIRIGANA_shi							98
#define HIRIGANA_ji							99
#define HIRIGANA_su							100
#define HIRIGANA_zu							101
#define HIRIGANA_se							102
#define HIRIGANA_ze							103
#define HIRIGANA_so							104
#define HIRIGANA_zo							105
#define HIRIGANA_ta							106
#define HIRIGANA_da							107
#define HIRIGANA_chi							108
#define HIRIGANA_di							109
#define HIRIGANA_tsu							110
#define HIRIGANA_du							111
#define HIRIGANA_te							112
#define HIRIGANA_to							113
#define HIRIGANA_do							114
#define HIRIGANA_na							115
#define HIRIGANA_ni							116
#define HIRIGANA_nu							117
#define HIRIGANA_ne							118
#define HIRIGANA_no							119
#define HIRIGANA_ha							120
#define HIRIGANA_ba							121
#define HIRIGANA_pa							122
#define HIRIGANA_hi							123
#define HIRIGANA_bi							124
#define HIRIGANA_pi							125
#define HIRIGANA_fu							126
#define HIRIGANA_bu							127
#define HIRIGANA_pu							128
#define HIRIGANA_he							129
#define HIRIGANA_be							130
#define HIRIGANA_pe							131
#define HIRIGANA_ho							132
#define HIRIGANA_bo							133
#define HIRIGANA_po							134
#define HIRIGANA_ma							135
#define HIRIGANA_mi							136
#define HIRIGANA_mu							137
#define HIRIGANA_me							138
#define HIRIGANA_mo							139
#define HIRIGANA_ya							140
#define HIRIGANA_yu							141
#define HIRIGANA_yo							142
#define HIRIGANA_ra							143
#define HIRIGANA_ri							144
#define HIRIGANA_ru							145
#define HIRIGANA_re							146
#define HIRIGANA_ro							147
#define HIRIGANA_wa							148
#define HIRIGANA_wi							149
#define HIRIGANA_we							150
#define HIRIGANA_wo							151
#define HIRIGANA_n							152
#define HIRIGANA_vu							153
#define HIRIGANA_va							HIRIGANA_QUESTIONMARK //154
#define HIRIGANA_vi							HIRIGANA_QUESTIONMARK //155
#define HIRIGANA_ve							HIRIGANA_QUESTIONMARK //156
#define HIRIGANA_vo							HIRIGANA_QUESTIONMARK //157
#define HIRIGANA_iteration					158
#define HIRIGANA_voiced_iteration		159
#define JAPANESE_middle_dot				160
#define JAPANESE_prolonged_sound			161
#define JAPANESE_full_stop					162
#define JAPANESE_0							163
#define JAPANESE_1							164
#define JAPANESE_2							165
#define JAPANESE_3							166
#define JAPANESE_4							167
#define JAPANESE_5							168
#define JAPANESE_6							169
#define JAPANESE_7							170
#define JAPANESE_8							171
#define JAPANESE_9							172
#define JAPANESE_EXCLAMATION				173
#define JAPANESE_QUESTIONMARK				174
#define JAPANESE_PERIOD						175
#define JAPANESE_COMMA						176
#define JAPANESE_QUOTE						177
#define JAPANESE_DOUBLEQUOTE				178
#define JAPANESE_COLON						179
#define JAPANESE_SEMICOLON					180
#define JAPANESE_FRONTSLASH				181
#define JAPANESE_BACKSLASH					182
#define JAPANESE_ASTERISK					183
#define JAPANESE_PLUS						184
#define JAPANESE_MINUS						185
#define JAPANESE_EQUALS						186
#define JAPANESE_UNDERSCORE				187
#define JAPANESE_CARET						188
#define JAPANESE_BACKQUOTE					189
#define JAPANESE_TILDE						190
#define JAPANESE_OPENPARENTHESIS			191
#define JAPANESE_CLOSEPARENTHESIS		192
#define JAPANESE_OPENANGLEBRACKET		193
#define JAPANESE_CLOSEANGLEBRACKET		194
#define JAPANESE_OPENCURLYBRACKET		195
#define JAPANESE_CLOSECURLYBRACKET		196
#define JAPANESE_OPENSQUAREBRACKET		197
#define JAPANESE_CLOSESQUAREBRACKET		198
#define JAPANESE_PIPE						199
#define JAPANESE_AT							200
#define JAPANESE_POUND						201
#define JAPANESE_DOLLAR						202
#define JAPANESE_PERCENT					203
#define JAPANESE_AMPERSAND					204
#define JAPANESE_BLOCK						205
#define JAPANESE_SPACE						206





//==============================================================================
#endif
//==============================================================================
