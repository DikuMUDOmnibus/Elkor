/***************************************************************************

 *  Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,        *

 *  Michael Seifert, Hans Henrik St{rfeldt, Tom Madsen, and Katja Nyboe.   *

 *                                                                         *

 *  Merc Diku Mud improvments copyright (C) 1992, 1993 by Michael          *

 *  Chastain, Michael Quan, and Mitchell Tse.                              *

 *                                                                         *

 *  In order to use any part of this Merc Diku Mud, you must comply with   *

 *  both the original Diku license in 'license.doc' as well the Merc       *

 *  license in 'license.txt'.  In particular, you may not remove either of *

 *  these copyright notices.                                               *

 *                                                                         *

 *  Much time and thought has gone into this software and you are          *

 *  benefitting.  We hope that you share your changes too.  What goes      *

 *  around, comes around.                                                  *

 ***************************************************************************/



#if defined(macintosh)

#include <types.h>

#else

#include <sys/types.h>

#endif

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <time.h>

#include "merc.h"

#include "player.h"



void do_grant( CHAR_DATA *ch, char *argument )

{

    CHAR_DATA *victim;

    char      arg1 [MAX_INPUT_LENGTH];

    char      arg2 [MAX_INPUT_LENGTH];

    int       inpart = 0;

    int       cost = 0;



    smash_tilde(argument);

    argument = one_argument( argument, arg1 );

    argument = one_argument( argument, arg2 );



    if (IS_NPC(ch)) return;



    if (!IS_CLASS(ch, CLASS_DROW))

    {

	    send_to_char("Huh?\n\r",ch);

	    return;

    }



    if ( arg1[0] == '\0' || arg2[0] == '\0' )

    {

	send_to_char( "Syntax: Grant <person> <power>\n\r", ch );

	send_to_char("Drowfire (2500),  Darkness (7500), Drowpoison (2500).\n\r",ch);

	send_to_char("Drowsight (5000), DrowBless (10000), Drowshield (5000),  Levitation (1000).\n\r", ch );

	if (ch->pcdata->stats[UNI_GEN] < 3)

	{

	send_to_char("Warrior (0), Mage (0), Cleric (0).\n\r", ch );

	}

	return;

    }



    if ( ( victim = get_char_world( ch, arg1 ) ) == NULL )

    {

	send_to_char( "Nobody by that name.\n\r", ch );

	return;

    }

	if (str_cmp(victim->clan,ch->clan) && ch->pcdata->stats[UNI_GEN] >1) 

	{

		send_to_char("Only on your clan!.\n\r", ch );

		return;

	}



    if ( IS_NPC(victim) )

    {

	send_to_char( "Not on NPC's.\n\r", ch );

	return;

    }



    if ( victim->level < 3)    

    {

	send_to_char( "Only on an avatar.\n\r", ch );

	return;

    }





    if (!str_cmp(arg2,"mage") || !str_cmp(arg2,"warrior") || !str_cmp(arg2, "cleric" ))

    {

	if (victim->pcdata->stats[UNI_GEN] < 3 )

	{	send_to_char("Not on them!\n\r", ch );

		return;

	}

	

	if(IS_IMMORTAL(victim))

	{

		send_to_char("Not on an Immortal.\n\r", ch);

		return;

	}

	if (!IS_CLASS(victim, CLASS_DROW)) 

	{

		send_to_char("Only on drows.\n\r", ch );

		return;

	}



	if (ch->pcdata->stats[UNI_GEN] != 2) 

	{

		send_to_char("Only for matrons.\n\r", ch );

		return; 

	}

	if (IS_SET(victim->special, SPC_DROW_WAR) 

	|| IS_SET(victim->special, SPC_DROW_MAG) 

	|| IS_SET(victim->special, SPC_DROW_CLE))

    {		

     send_to_char( "They already have a class.\n\r", ch );

	 return;

	}

	if (!str_cmp(arg2, "mage"))

		SET_BIT(victim->special, SPC_DROW_MAG);

	else if (!str_cmp(arg2, "cleric"))

		SET_BIT(victim->special, SPC_DROW_CLE);

	else if (!str_cmp(arg2, "warrior"))

		SET_BIT(victim->special, SPC_DROW_WAR);



	save_char_obj(victim);

	return;

    }





    if (!str_cmp(arg2,"drowfire")) 

	{inpart = DPOWER_DROWFIRE; cost = 2500;}

    else if (!str_cmp(arg2,"darkness"))

	{inpart = DPOWER_DARKNESS; cost= 7500;}

	else if (!str_cmp(arg2,"drowbless"))

	{inpart = DPOWER_DROWBLESS; cost= 10000;}

    else if (!str_cmp(arg2,"drowsight"))

	{inpart = DPOWER_DROWSIGHT; cost= 5000;}

    else if (!str_cmp(arg2,"drowshield"))

     	{inpart = DPOWER_DROWSHIELD; cost = 5000;}

    else if (!str_cmp(arg2,"levitation"))

	{inpart = DPOWER_LEVITATION; cost = 1000;}

    else if (!str_cmp(arg2,"drowpoison"))

	{inpart = DPOWER_DROWPOISON; cost = 2500;}

    else

    {

	send_to_char("Please select a power from:\n\r",ch);

        send_to_char("Drowfire (2500),  Darkness (7500), Drowpoison  (1000).\n\r",ch);

	send_to_char("Drowsight (5000),  Drowshield (5000), DrowBless (10000), Levitation (1000).\n\r", ch );



    if (ch->pcdata->stats[UNI_GEN] < 3) 

    {

    send_to_char("Warrior (0), Mage (0), Cleric (0).\n\r", ch );

    }

	return;

    }

    if (IS_SET(victim->pcdata->powers[1], inpart))

    {

	send_to_char("They have already got that power.\n\r",ch);

	return;

    }

    if (ch->pcdata->stats[DROW_POWER] < cost) 

    {

	send_to_char("You have insufficient power to grant that gift.\n\r",ch);

	return;

    }

    SET_BIT(victim->pcdata->powers[1], inpart);

    ch->pcdata->stats[DROW_POWER]   -= cost;

    if (victim != ch) send_to_char("You have been granted a gift from your matron!\n\r",victim);

    send_to_char("Ok.\n\r",ch);

    if (victim != ch) save_char_obj(ch);

    save_char_obj(victim);

    return; 

}



void do_drowcreate( CHAR_DATA *ch, char *argument )

{

    OBJ_INDEX_DATA *pObjIndex;

    OBJ_DATA *obj;

    char arg[MAX_INPUT_LENGTH];

    int vnum = 0;



    argument = one_argument( argument, arg );



    if (IS_NPC(ch)) return;



    if (!IS_CLASS(ch, CLASS_DROW))

    {

	    send_to_char("Huh?\n\r",ch);

	    return;

    }



    if (arg[0] == '\0')

    {

	send_to_char("Please specify what kind of equipment you want to create.\n\r", ch );

	send_to_char("Sword, Piwafwi, Boots, Armor, Mask, Bracers.\n\r", ch );

	return;

    }

    if      (!str_cmp(arg,"sword"     )) vnum = 29600;

    else if (!str_cmp(arg,"piwafwi"   )) vnum = 29601;

    else if (!str_cmp(arg,"armor"    )) vnum = 29602;

    else if (!str_cmp(arg,"boots"   )) vnum = 29603;

    else if (!str_cmp(arg,"mask" )) vnum = 29604;

    else if (!str_cmp(arg,"bracers"    )) vnum = 29605;

    else

    {

	send_to_char("That is an invalid type.\n\r", ch );

	return;

    }

    if ( ch->pcdata->stats[DROW_POWER] < 7500)

    {

	send_to_char("It costs 7500 points of power to create a piece of drow armour.\n\r",ch);

	return;

    }

    if ( vnum == 0 || (pObjIndex = get_obj_index( vnum )) == NULL)

    {

	send_to_char("Missing object, please inform KaVir.\n\r",ch);

	return;

    }

    ch->pcdata->stats[DROW_POWER] -= 7500;

    obj = create_object(pObjIndex, 50);

    obj_to_char(obj, ch);

    act("$p appears in your hands.",ch,obj,NULL,TO_CHAR);

    act("$p appears in $n's hands.",ch,obj,NULL,TO_ROOM);

    return;

}



void do_favor( CHAR_DATA *ch, char *argument )

{

    char      buf [MAX_INPUT_LENGTH];

    CHAR_DATA *victim;

    char      arg [MAX_INPUT_LENGTH];



    argument = one_argument( argument, arg );



    if (IS_NPC(ch)) return;



    if (!IS_CLASS(ch, CLASS_DROW) || ch->pcdata->stats[UNI_GEN] > 2) 

    {

	send_to_char("Huh?\n\r",ch);

	return;

    }



    if (arg[0] == '\0' )

    {

	send_to_char( "Give Lloth's favor to whom?\n\r", ch );

	return;

    }



    if ( ( victim = get_char_room( ch, arg ) ) == NULL )

    {

	send_to_char( "They aren't here.\n\r", ch );

	return;

    }



    if ( IS_NPC(victim) )

    {

	send_to_char( "Not on NPC's.\n\r", ch );

	return;

    }



    if ( ch == victim )

    {

	send_to_char("Not on yourself.\n\r", ch );

	return;

    }



    if (IS_CLASS(victim, CLASS_MAGE))

    {

	send_to_char( "Not on a mage.\n\r", ch );

	return;

    }



    if ( victim->level != LEVEL_AVATAR && !IS_IMMORTAL(victim) )

    {

	send_to_char( "Only on avatars.\n\r", ch );

	return;

    }



    if (!IS_IMMUNE(victim,IMM_DEMON))

    {

	send_to_char( "Not on an unwilling person.\n\r", ch);

	return;

    }

    if (IS_CLASS(victim, CLASS_DROW)) 

    {

	send_to_char("They are already a drow.\n\r", ch );

		return;

	}

    if (IS_CLASS(victim, CLASS_DEMON) || IS_SET(victim->special, SPC_CHAMPION))

    {

	send_to_char("Not on a demon!\n\r",ch);

	return;

    }



	if (IS_CLASS(victim, CLASS_VAMPIRE)) 

	{

		send_to_char("Not on a vampire!\n\r", ch );

		return;

	}

	

	if (IS_CLASS(victim, CLASS_MONK))

	{

	send_to_char("Not on monks!\n\r", ch);

	return;

	}

	

	if (IS_CLASS(victim, CLASS_NINJA)) 

	{

		send_to_char("Not on a ninja!\n\r", ch );

		return;

	}



	if (IS_CLASS(victim, CLASS_WEREWOLF)) 

	{

	send_to_char("Not on a werewolf!\n\r", ch );

	return;

	}

    if ( IS_CLASS(victim, CLASS_HIGHLANDER) )

    {

	send_to_char( "Not on a highlander.\n\r", ch );

	return;

    }

    

    if (ch->exp < 10000)

    {

	send_to_char("You cannot afford the 10,000 exp.\n\r",ch);

	return;

    }



    ch->exp = ch->exp - 10000;

    act("You make $N a drow!", ch, NULL, victim, TO_CHAR);

    act("$n makes $N a drow!", ch, NULL, victim, TO_NOTVICT);

    act("$n makes you a drow!", ch, NULL, victim, TO_VICT);

    victim->class=0;

    victim->class=CLASS_DROW;

    victim->special=0;



    if (IS_CLASS(victim, CLASS_VAMPIRE)) do_mortalvamp(victim,"");

    REMOVE_BIT(victim->act, PLR_HOLYLIGHT);

    REMOVE_BIT(victim->act, PLR_WIZINVIS);

    REMOVE_BIT(victim->special, SPC_SIRE);

    REMOVE_BIT(victim->special, SPC_ANARCH);

    victim->pcdata->stats[UNI_RAGE] = 0;

    victim->pcdata->stats[UNI_GEN] = ch->pcdata->stats[UNI_GEN] + 1;

	victim->special = 0;

    free_string(victim->morph);

    victim->morph=str_dup("");

                free_string(victim->clan);

            victim->clan=str_dup(ch->clan);



    free_string(victim->lord);

    if (ch->pcdata->stats[UNI_GEN] == 1)

        victim->lord=str_dup(ch->name);

    else

    {

        sprintf(buf,"%s %s",ch->lord,ch->name);

        victim->lord=str_dup(buf);

    }

 

    save_char_obj(ch);

    save_char_obj(victim);

    return;

}



void do_drows( CHAR_DATA *ch, char *argument )

{

    char buf[MAX_STRING_LENGTH];

    char arg[MAX_INPUT_LENGTH];

    char lord[MAX_INPUT_LENGTH];

    CHAR_DATA *gch;



    one_argument( argument, arg );



    if (IS_NPC(ch)) return;

    if (!IS_CLASS(ch, CLASS_DROW))

    {

	send_to_char("Huh?\n\r",ch);

	return;

    }



	if (ch->pcdata->stats[UNI_GEN] < 3)

		strcpy(lord,ch->name);

	else strcpy(lord,ch->lord);

    sprintf( buf, "The drow followers of %s:\n\r", lord );

    send_to_char( buf, ch );

    send_to_char("[      Name      ] [ Hits ] [ Mana ] [ Move ] [  Exp  ] [   Power   ]\n\r", ch );

    for ( gch = char_list; gch != NULL; gch = gch->next )

    {

	if ( IS_NPC(gch) ) continue;

	if ( !IS_CLASS(gch, CLASS_DROW)) 

	    continue;

	if ( !str_cmp(ch->lord,lord) || !str_cmp(ch->name,lord))

	{

	    sprintf( buf,

	    "[%-16s] [%-6d] [%-6d] [%-6d] [%7d] [ %-9d ]\n\r",

		capitalize( gch->name ),

		gch->hit,gch->mana,gch->move,

		gch->exp, gch->pcdata->stats[DROW_POWER]);

		send_to_char( buf, ch );

	}

    }

    return;

}



void do_drowfire( CHAR_DATA *ch, char *argument ) 

{



    CHAR_DATA *victim;

    char arg [MAX_INPUT_LENGTH];

    int sn;

    int level;

    int spelltype;



	argument = one_argument(argument, arg);



	if (IS_NPC(ch)) return;



	if(!IS_CLASS(ch, CLASS_DROW) || !IS_SET(ch->pcdata->powers[1],DPOWER_DROWFIRE)) 

	{

		send_to_char("Huh?\n\r", ch );

		return;

	}



    if ( ( victim = get_char_room( ch, arg ) ) == NULL )

	if ((victim = ch->fighting) == NULL)

    {

        send_to_char( "They aren't here.\n\r", ch );

        return;

    }



    if ( ch == victim )

    {

        send_to_char( "Not on yourself.\n\r", ch );

        return;

    }



	if (ch->mana < 100) 

	{

		send_to_char("You don't have enough mana.\n\r", ch );

		return;

	}



    if ( ( sn = skill_lookup( "drowfire" ) ) < 0 ) return;

    spelltype = skill_table[sn].target;

    level = ch->spl[spelltype] * 0.5;

    (*skill_table[sn].spell_fun) ( sn, level, ch, victim );

    WAIT_STATE( ch, 12 );

	ch->mana = ch->mana - 500;

    return;

}



void do_heal( CHAR_DATA *ch, char *argument) 

{

	if (IS_NPC(ch)) return;



	if (!IS_CLASS(ch, CLASS_DROW) || (!IS_SET(ch->special,SPC_DROW_CLE)

	&& ch->pcdata->stats[UNI_GEN] > 2)) 

	{

		send_to_char("Huh?\n\r", ch );

		return;

	}



	if (ch->mana < 100) 

	{

		send_to_char("You don't have enough mana.\n\r", ch );

		return;

	}



	ch->mana = ch->mana - 100;

	ch->hit = ch->hit + 250;

	if (ch->hit > ch->max_hit) ch->hit = ch->max_hit;

	send_to_char("Lloth heals you.\n\r",ch);

	act("$n is healed by Lloth.",ch,NULL,NULL,TO_ROOM);

	WAIT_STATE(ch, 12);

	return;

}

void do_drowbless( CHAR_DATA *ch, char *argument ) 

{

    int sn;

    int level;

    int spelltype;

	if(!IS_CLASS(ch, CLASS_DROW) ) 

	{

		send_to_char("Huh?\n\r", ch );

		return;

	}

	

  	if ( IS_CLASS(ch, CLASS_DROW) && !IS_SET(ch->pcdata->powers[1], DPOWER_DROWBLESS))

  	{

  	send_to_char("You have not been granted Drow Bless.\n\r", ch);

  	return;

  	}



	if (ch->mana < 1000) 

	{

		send_to_char("You don't have enough mana.\n\r", ch );

		return;

	}



    if ( ( sn = skill_lookup( "drowbless" ) ) < 0 ) return;

    spelltype = skill_table[sn].target;

    level = ch->spl[spelltype] * 0.5;

    (*skill_table[sn].spell_fun) ( sn, level, ch, ch );

    WAIT_STATE( ch, 12 );

	ch->mana = ch->mana - 1000;

    return;

}


void do_darkness(CHAR_DATA *ch, char *argument) 

{

    int sn;

    int level;

    int spelltype;

	bool blah = FALSE;



	if (IS_NPC(ch)) return;



	if (!IS_CLASS(ch, CLASS_DROW) || !IS_SET(ch->pcdata->powers[1], DPOWER_DARKNESS)) 

	{

	send_to_char("Huh?\n\r", ch );

		return;

	}



	if (IS_AFFECTED(ch, AFF_DARKNESS)) 

	{

		send_to_char("You are already surrounded in darkness.\n\r",ch);

		return;

	}



	if (ch->move < 500) 

	{

		send_to_char("You don't have enough move.\n\r", ch );

		return;

	}



    if ( ( sn = skill_lookup( "darkness" ) ) < 0 ) return;

    spelltype = skill_table[sn].target;

    level = 50;

    (*skill_table[sn].spell_fun) ( sn, level, ch, NULL);



	if (IS_SET(ch->extra, TIED_UP)) 

	{

		REMOVE_BIT(ch->extra, TIED_UP);

		blah = TRUE;

	}



	if (IS_AFFECTED(ch, AFF_WEBBED)) 

	{

		REMOVE_BIT(ch->affected_by, AFF_WEBBED);

		blah = TRUE;

	}



	if (blah) send_to_char("The darkness sets you free.\n\r", ch );		



    WAIT_STATE( ch, 4 );

	ch->move = ch->move - 500;

    return;

}



void do_drowsight( CHAR_DATA *ch, char *argument) 

{

    if ( IS_NPC(ch) )

        return;

 

	if (!IS_CLASS(ch, CLASS_DROW)) 

	{

		send_to_char("Huh?\n\r", ch );

		return;

	}



	if (!IS_SET(ch->pcdata->powers[1], DPOWER_DROWSIGHT)) 

	{

		send_to_char("You don't have the power of drow sight.\n\r", ch );

		return;

	}



	if (IS_SET(ch->act, PLR_DROWSIGHT)) 

	{

		REMOVE_BIT(ch->act, PLR_DROWSIGHT);

		REMOVE_BIT(ch->act, PLR_HOLYLIGHT);

        send_to_char( "Your senses return to normal.\n\r", ch );

    }

	else 

	{

     SET_BIT(ch->act, PLR_HOLYLIGHT);

	 SET_BIT(ch->act, PLR_DROWSIGHT);

     send_to_char( "Your senses increase to incredible proportions.\n\r", ch);

	}

	return;

}



void do_chaosblast( CHAR_DATA *ch, char *argument )

{

    CHAR_DATA *victim;

    char arg [MAX_INPUT_LENGTH];

    int sn;

    int level;

    int spelltype;



    argument = one_argument( argument, arg );

    if (IS_NPC(ch)) return;



    if (!IS_CLASS(ch, CLASS_DROW) || (!IS_SET(ch->special, SPC_DROW_MAG)

 	&& ch->pcdata->stats[UNI_GEN] > 2))

    {

        send_to_char("Huh?\n\r",ch);

        return;

    }



    if ( ( victim = get_char_room( ch, arg ) ) == NULL )

	if ((victim = ch->fighting) == NULL)

    {

        send_to_char( "They aren't here.\n\r", ch );

        return;

    }

    

	if (ch->mana < 100) 

	{

		send_to_char("You don't have enough mana.\n\r", ch);

		return;

	}



    if ( ( sn = skill_lookup( "chaos blast" ) ) < 0 ) return;

    spelltype = skill_table[sn].target;

    level = ch->spl[spelltype] * 1.0;

	level = level * 3.0;

	act("You concentrate your power on $N.",ch,NULL,victim,TO_CHAR);

	act("$n concentrates $s power on you.",ch,NULL,victim,TO_VICT);

    (*skill_table[sn].spell_fun) ( sn, level, ch, victim );

    WAIT_STATE( ch, 10 );

	ch->mana = ch->mana - 100;

    return;

}



void do_offering( CHAR_DATA *ch, char *arg )

{

    CHAR_DATA *victim;

    char buf [MAX_STRING_LENGTH];

    

    if ( !IS_CLASS(ch, CLASS_DROW) )

    {

      send_to_char("Huh?\n\r", ch);

      return;

    }

 

    if ( arg[0] == '\0' )

    {

	send_to_char("Who do you wish to give your power to?\n\r",ch);

	return;

    }

    else 

    {

	if (ch->pcdata->stats[DROW_POWER] < 1)

	{

	    send_to_char("Nothing happens.\n\r",ch);

	    return;

	}

	if ( ( victim = get_char_world(ch, arg) ) == NULL )

	{

	    send_to_char("They are not here.\n\r",ch);

	    return;

	}

	act("You feel your offering flow into $N", ch,NULL,victim,TO_CHAR);

	act("$n's offering flows into you.",ch,NULL,victim,TO_VICT);

	send_to_char("You feel power pour into your body.\n\r",victim);

	if (ch->pcdata->stats[DROW_POWER] == 1)

	    sprintf(buf,"You receive a single point of power.\n\r");

	else

	    sprintf(buf,"You receive %d points of power.\n\r",

		ch->pcdata->stats[DROW_POWER]);

	send_to_char(buf,victim);

	act("$n is briefly surrounded by a halo of power.",victim,NULL,NULL,TO_ROOM);

	victim->pcdata->stats[DROW_POWER] += ch->pcdata->stats[DROW_POWER];

	ch->pcdata->stats[DROW_POWER] = 0;

	return;

    }



    return;

}

