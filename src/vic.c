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



void do_level( CHAR_DATA *ch, char *argument )

{

    char arg       [MAX_INPUT_LENGTH];

    char skill  [20];  

    char stance [10];

    one_argument( argument, arg );



    if (IS_NPC(ch)) return;  

    

    send_to_char("                  -= Weapon Levels =-\n\r", ch);

    sprintf(skill, "Slice : %-10d", ch->wpn[1]);

    send_to_char( skill, ch );

    sprintf(skill, "Stab : %-10d", ch->wpn[2]);

    send_to_char( skill, ch );      

    sprintf(skill, "Slash : %-10d", ch->wpn[3]);

    send_to_char( skill, ch );  

    sprintf(skill, "Whip : %-10d\n\r", ch->wpn[4]);

    send_to_char( skill, ch ); 

    sprintf(skill, "Claw : %-10d", ch->wpn[5]);

    send_to_char( skill, ch );

    sprintf(skill, "Blast : %-10d", ch->wpn[6]);

    send_to_char( skill, ch );

    sprintf(skill, "Pound : %-10d", ch->wpn[7]);

    send_to_char( skill, ch );

    sprintf(skill, "Crush : %-10d\n\r", ch->wpn[8]);

    send_to_char( skill, ch );

    sprintf(skill, "Grep : %-10d", ch->wpn[9]);

    send_to_char( skill, ch ); 

    sprintf(skill, "Bite : %-10d", ch->wpn[10]);

    send_to_char( skill, ch );  

    sprintf(skill, "Pierce : %-10d", ch->wpn[11]);

    send_to_char( skill, ch );

    sprintf(skill, "Suck : %-10d\n\r", ch->wpn[12]);

    send_to_char( skill, ch );        

    sprintf(skill, "Unarmed : %-10d\n\r\n", ch->wpn[0]);

    send_to_char( skill, ch );    



    

    send_to_char("                  -= Stance Levels =-\n\r", ch);

    sprintf(skill, "Viper : %-10d", ch->stance[1]);

    send_to_char( skill, ch );

    sprintf(skill, "Crane : %-10d", ch->stance[2]);

    send_to_char( skill, ch );

    sprintf(skill, "Crab : %-10d", ch->stance[3]);

    send_to_char( skill, ch );

    sprintf(skill, "Mongoose : %-10d\n\r", ch->stance[4]);

    send_to_char( skill, ch );

    sprintf(skill, "Bull  : %-10d", ch->stance[5]);

    send_to_char( skill, ch );

    sprintf(skill, "Mantis : %-10d", ch->stance[6]);

    send_to_char( skill, ch );

    sprintf(skill, "Dragon : %-10d", ch->stance[7]);

    send_to_char( skill, ch );

    sprintf(skill, "Tiger : %-10d\n\r", ch->stance[8]);

    send_to_char( skill, ch );

    sprintf(skill, "Monkey : %-10d", ch->stance[9]);

    send_to_char( skill, ch );

    sprintf(skill, "Swallow : %-10d\n\r\n", ch->stance[10]);

    send_to_char( skill, ch );

    

    send_to_char("                  -= Spell Levels =-\n\r", ch);

    sprintf(skill, "Purple : %-10d", ch->spl[0]);

    send_to_char( skill, ch );

    sprintf(skill, "Blue : %-10d", ch->spl[2]);

    send_to_char( skill, ch );

    sprintf(skill, "Red : %-10d\n\r", ch->spl[1]);

    send_to_char( skill, ch );    

    sprintf(skill, "Green : %-10d", ch->spl[3]);

    send_to_char( skill, ch );

    sprintf(skill, "Yellow : %-10d\n\r\n", ch->spl[4]);

    send_to_char( skill, ch );

    

    send_to_char("                   -= Misc. Things =-\n\r", ch);

    sprintf(skill, "Recall Room : %d     ", ch->home);

    send_to_char( skill, ch );

    sprintf(skill, "Trust : %d\n\r", ch->trust);

    send_to_char( skill, ch );



     if ( ch->stance[11] == 1 )

      sprintf(stance, " Viper\n\r" );

     else if ( ch->stance[11] == 2 )

      sprintf(stance, " Crane\n\r" );

     else if ( ch->stance[11] == 3 )

      sprintf(stance, " Crab\n\r" );  

     else if ( ch->stance[11] == 4 )

      sprintf(stance, " Mongoose\n\r" );  

     else if ( ch->stance[11] == 5 )

      sprintf(stance, " Bull\n\r" );  

     else if ( ch->stance[11] == 6 )

      sprintf(stance, " Mantis\n\r" );  

     else if ( ch->stance[11] == 7 )

      sprintf(stance, " Dragon\n\r" );  

     else if ( ch->stance[11] == 8 )

      sprintf(stance, " Tiger\n\r" );  

     else if ( ch->stance[11] == 9 )

      sprintf(stance, " Monkey\n\r" );  

     else if ( ch->stance[11] == 10 )

      sprintf(stance, " Swallow\n\r" ); 

     else if ( ch->stance[11] == -1 || ch->stance[11] == 15 )

      sprintf(stance, " None\n\r" );

    

      sprintf(skill, "Autostance:  %s", stance);

      send_to_char( skill, ch );

 

	 send_to_char("\n                   -= Class Things =-\n\r", ch);

    

    if ( IS_CLASS(ch, CLASS_DEMON) )

     send_to_char("You are an Angel!\n\r", ch);

    if ( IS_CLASS(ch, CLASS_MAGE) )

     send_to_char("You are a mage!\n\r", ch);    

     if ( IS_CLASS(ch, CLASS_WEREWOLF) )

     send_to_char("You are a werewolf!\n\r", ch);

     if ( IS_CLASS(ch, CLASS_NINJA) )

     send_to_char("You are a ninja!\n\r", ch);

    if ( IS_CLASS(ch, CLASS_VAMPIRE) )

     send_to_char("You are a vampire!\n\r", ch);

    if ( IS_CLASS(ch, CLASS_HIGHLANDER) )

     send_to_char("You are a highlander!\n\r", ch);

    if ( IS_CLASS(ch, CLASS_DROW) )

     send_to_char("You are a drow!\n\r", ch);    

 

 if (IS_CLASS(ch, CLASS_VAMPIRE) )

 {



    sprintf(skill, "Generation : %d     ", ch->pcdata->stats[UNI_GEN]);

    send_to_char( skill, ch );	

	if (ch->pcdata->rank == AGE_METHUSELAH)

	  send_to_char("You are a Methuselah!\n\r",ch);

	else if (ch->pcdata->rank == AGE_ELDER)

	  send_to_char("You are an Elder!\n\r",ch);

	else if (ch->pcdata->rank == AGE_ANCILLA)

	  send_to_char("You are an Ancilla!\n\r",ch);

	else if (ch->pcdata->rank == AGE_NEONATE)

	  send_to_char("You are a Neonate!\n\r", ch);

	else

	  send_to_char("You are a Childe!\n\r", ch);

	if ( IS_SET(ch->special, SPC_PRINCE) )

	  send_to_char("You are a prince!\n\r", ch);

 }

 

 if (IS_CLASS(ch, CLASS_NINJA) )

 {

    sprintf(skill, "Generation : %d\n\r", ch->pcdata->stats[UNI_GEN]);

    send_to_char( skill, ch );	

	if ( IS_SET(ch->special, SPC_PRINCE) )

	  send_to_char("You can discipline people!\n\r", ch);

 }

 

 if (IS_CLASS(ch, CLASS_WEREWOLF) )

 {

    sprintf(skill, "Generation : %d\n\r", ch->pcdata->stats[UNI_GEN]);

    send_to_char( skill, ch );	

    if ( IS_SET(ch->special, SPC_SIRE) && ch->pcdata->stats[UNI_GEN] > 2 )

      send_to_char("You are able to spread the gift!\n\r", ch);

    if ( IS_SET(ch->special, SPC_PRINCE) && ch->pcdata->stats[UNI_GEN] > 2 )

	  send_to_char("You are your a shaman!\n\r", ch);

	if ( ch->pcdata->stats[UNI_FORM0] == 1 )

	  send_to_char("You are in Homid form.\n\r", ch);

	else if ( ch->pcdata->stats[UNI_FORM0] == 2 )

	  send_to_char("You are in Raginos form.\n\r", ch);

	else if ( ch->pcdata->stats[UNI_FORM0] == 3 )

	  send_to_char("You are in Crinos form.\n\r", ch);

	else if ( ch->pcdata->stats[UNI_FORM0] == 4 )

	  send_to_char("You are in Hispo form.\n\r", ch);

	else if ( ch->pcdata->stats[UNI_FORM0] == 5 )

	  send_to_char("You are in Lupus form.\n\r", ch);

 }

 

    send_to_char("\n\r* You can type spells, stances, or weapons to see your spell, stance, or weapon levels in words.\n\r", ch);

    return;

}



void do_class( CHAR_DATA *ch, char *argument )

{

    CHAR_DATA *victim;

    char      arg1 [MAX_INPUT_LENGTH];

    char      arg2 [MAX_INPUT_LENGTH];

    argument = one_argument( argument, arg1 );

    argument = one_argument( argument, arg2 );

        

    if ( IS_NPC(ch) ) return;

    

    if ( arg1[0] == '\0' || arg2[0] == '\0' )

    {

	send_to_char( "Syntax: class <char> <class>.\n\r", ch );

	send_to_char("      Classes:\n\r", ch );

    send_to_char("None, ", ch);

    send_to_char("Angel, ", ch);

    send_to_char("Arch-Angel , ", ch);

    send_to_char("Purple Mage, Blue Mage, Yellow Mage, Green Mage, Red Mage, ", ch);

    send_to_char("Werewolf, ", ch);

    send_to_char("Ninja, ", ch);

    send_to_char("Monk, ", ch);

    send_to_char("Vampire, ", ch);

    send_to_char("Highlander, ", ch);

    send_to_char("Drow, ", ch);

	return;

    }

    

    if ( ( victim = get_char_room( ch, arg1 ) ) == NULL )

    {

	send_to_char( "That player is not here.\n\r", ch);

	return;

    }



         if ( !str_cmp( arg2, "none"       ) ) 

    {

    /* Used to make sure the person has enough "stuff" to change */

	victim->pcdata->condition[COND_THIRST] = 10000;

	victim->move = 10000;

	victim->mana = 10000;



	victim->pcdata->powers[WPOWER_BEAR]   = 4;

    victim->pcdata->powers[WPOWER_LYNX]   = 4;

	victim->pcdata->powers[WPOWER_BOAR]   = 4;

	victim->pcdata->powers[WPOWER_OWL]    = 4;

	victim->pcdata->powers[WPOWER_SPIDER] = 4; 

	victim->pcdata->powers[WPOWER_WOLF]   = 4;

	victim->pcdata->powers[WPOWER_HAWK]   = 4;

	victim->pcdata->powers[WPOWER_MANTIS] = 4;



	if ( IS_CLASS(victim, CLASS_WEREWOLF)

	     || IS_CLASS(victim, CLASS_VAMPIRE) ) do_unwerewolf(victim,"");

	if ( IS_CLASS(victim, CLASS_WEREWOLF) ) do_shift(victim,"homid");

	if (IS_VAMPAFF(victim,VAM_DISGUISED) ) do_mask(victim,"self");

    victim->pcdata->stats[UNI_FORM0] = 0;

 

/* All classes in general */   

    if (IS_VAMPAFF(victim,VAM_FANGS) )

    {

	 send_to_char("Your fangs slide back into your gums.\n\r",victim);

	 act("$N's fangs slide back into $s gums.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_FANGS);

    }

    if (IS_CLASS(victim, CLASS_VAMPIRE) && IS_VAMPAFF(victim,VAM_CLAWS) ) 

	{

	    send_to_char("Your claws slide back under your nails.\n\r",victim);

	    act("$N's claws slide back under $s nails.", ch, NULL, victim, TO_ROOM);

	    REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CLAWS);

	}

	else if (IS_CLASS(victim, CLASS_NINJA) && IS_VAMPAFF(victim,VAM_CLAWS) ) 

 	{

	 	send_to_char("You shove your iron claws up your sleeves\n\r",victim);

	    act("$N shoves $S iron claws up $e sleeves.", ch, NULL, victim, TO_ROOM);

	    REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CLAWS);

    }

    else if (IS_CLASS(victim, CLASS_WEREWOLF) && IS_VAMPAFF(victim,VAM_CLAWS) ) 

    {

    	send_to_char("Your talons slide back into your fingers.\n\r",victim);

	    act("$N's talons slide back into $s fingers.",ch,NULL,victim,TO_ROOM);

    	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CLAWS);

    }



    if (IS_VAMPAFF(victim,VAM_NIGHTSIGHT) )

    {

	 send_to_char("The red glow in your eyes fades.\n\r",victim);

	 act("The red glow in $N's eyes fades.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_NIGHTSIGHT);

    }

    if (IS_AFFECTED(victim,AFF_SHADOWSIGHT) )

    {

	 send_to_char("You can no longer see between planes.\n\r",victim);

	 REMOVE_BIT(victim->affected_by, AFF_SHADOWSIGHT);

    }

    

    if (IS_IMMUNE(victim,IMM_SHIELDED) )

    {

     send_to_char("You stop shielding your aura.\n\r",victim);

     REMOVE_BIT(victim->immune, IMM_SHIELDED);

    }

    

    if (IS_VAMPAFF(victim,VAM_DISGUISED) )

    {

     free_string( victim->morph );

     victim->morph = str_dup( victim->name );

     send_to_char("You transform into yourself.\n\r", victim);

     REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_DISGUISED);

    }

    

    if (IS_AFFECTED(victim,AFF_SHADOWPLANE) )

    {

     send_to_char("You fade back into the real world.\n\r",victim);

	 act("The shadows flicker and $N fades into existance.",ch,NULL,victim,TO_ROOM);

	 REMOVE_BIT(victim->affected_by,AFF_SHADOWPLANE);

	 do_look(ch,"auto");

	}

	

	if (IS_SET(victim->act, PLR_WIZINVIS) )

	{

	 REMOVE_BIT(victim->act, PLR_WIZINVIS);

	 send_to_char( "You slowly fade into existence.\n\r", victim );

	}

	

	if (IS_SET(victim->act, PLR_HOLYLIGHT) )

	{

	 REMOVE_BIT(victim->act, PLR_HOLYLIGHT);

	 REMOVE_BIT(victim->act, PLR_DROWSIGHT);

	 send_to_char( "Your senses return to normal.\n\r", victim );

	}

	

/* Angel Stuff */

    if (IS_DEMAFF(victim,DEM_HORNS) && IS_CLASS(victim, CLASS_DEMON) )

    {

	 send_to_char("Your halo dissapears.\n\r",victim);

	 act("$N's halo dissapears.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->powers[DPOWER_CURRENT], DEM_HORNS);

	}

	

	if (IS_DEMAFF(victim,DEM_HOOVES) && IS_CLASS(victim, CLASS_DEMON) )

    {

	 send_to_char("The light around your feet vanishes.\n\r",victim);

	 act("The light around $N's feet vanishes .", ch, NULL,victim,TO_ROOM);

	 REMOVE_BIT(victim->pcdata->powers[DPOWER_CURRENT], DEM_HOOVES);

    }

    

    if (IS_DEMAFF(victim,DEM_WINGS) && IS_CLASS(victim, CLASS_DEMON) )

    {

	if (IS_DEMAFF(victim,DEM_UNFOLDED) && IS_CLASS(victim, CLASS_DEMON) )

	{

	    send_to_char("Your wings fold up behind your back.\n\r",victim);

	    act("$N's wings fold up behind $s back.", ch, NULL, victim, TO_ROOM);

	    REMOVE_BIT(victim->pcdata->powers[DPOWER_CURRENT], DEM_UNFOLDED);

	}

	send_to_char("Your wings slide into your back.\n\r",victim);

	act("$N's wings slide into $s back.", ch, NULL, victim, TO_ROOM);

	REMOVE_BIT(victim->pcdata->powers[DPOWER_CURRENT], DEM_WINGS);

    }

    

	if ( IS_EXTRA(victim, EXTRA_OSWITCH) ) 

	{

	 do_humanform(victim,"");

	}

	

	REMOVE_BIT(victim->special, SPC_CHAMPION );

	REMOVE_BIT(victim->special, SPC_INCONNU );

	REMOVE_BIT(victim->special, SPC_ANARCH );

    REMOVE_BIT(victim->special, SPC_SIRE);

    REMOVE_BIT(victim->special, SPC_PRINCE);

    REMOVE_BIT(victim->special, SPC_DEMON_LORD);

    REMOVE_BIT(victim->special, SPC_DROW_WAR );

    REMOVE_BIT(victim->special, SPC_DROW_MAG );

    REMOVE_BIT(victim->special, SPC_DROW_CLE );

	REMOVE_BIT(victim->affected_by, AFF_POLYMORPH);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CHANGED);

    REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_MIST);

	REMOVE_BIT(victim->affected_by, AFF_ETHEREAL);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_FLYING);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_SONIC);

	REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_BAT);

	REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_WOLF);

	

	victim->pcdata->powers[DPOWER_FLAGS] = 0;

  	victim->pcdata->stats[DEMON_TOTAL] = 0;

	victim->pcdata->stats[DEMON_CURRENT] = 0;

	victim->pcdata->powers[WPOWER_BEAR]   = 0;

    victim->pcdata->powers[WPOWER_LYNX]   = 0;

	victim->pcdata->powers[WPOWER_BOAR]   = 0;

	victim->pcdata->powers[WPOWER_OWL]    = 0;

	victim->pcdata->powers[WPOWER_SPIDER] = 0; 

	victim->pcdata->powers[WPOWER_WOLF]   = 0;

	victim->pcdata->powers[WPOWER_HAWK]   = 0;

	victim->pcdata->powers[WPOWER_MANTIS] = 0;

  	victim->pcdata->powers[NPOWER_SORA]     = 0;

  	victim->pcdata->powers[NPOWER_CHIKYU]   = 0;

	victim->pcdata->powers[NPOWER_NINGENNO] = 0;

	victim->pcdata->powers[1] = 0;

	victim->pcdata->condition[COND_THIRST] = 0;

	victim->move = victim->max_move;

	victim->mana = victim->max_mana;

	victim->hit = victim->max_hit;

	victim->pcdata->rank = 0;

	

	victim->pcdata->stats[UNI_RAGE] = 0;

    free_string(victim->lord);

    victim->lord     = str_dup( "" );

    free_string(victim->clan);

    victim->clan     = str_dup( "" );

    victim->pcdata->stats[UNI_GEN]     = 0;

    victim->pcdata->stats[UNI_AFF]     = 0;

    victim->pcdata->stats[UNI_CURRENT] = -1;

    victim->beast = 15;

    

    victim->class = 0;

    victim->trust = 0;

    victim->level = 2;

    send_to_char("You are classless now!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "angel"      ) ) 

    {

    victim->class = 1;

    victim->level = 3;

    SET_BIT( victim->special, SPC_CHAMPION );

    victim->lord=str_dup(ch->name);

    send_to_char("You are now an angel!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "arch-angel"      ) ) 

    {

    victim->class = 1;

    victim->level = 3;

    SET_BIT( victim->special, SPC_DEMON_LORD );

    victim->lord=str_dup(victim->name);

    send_to_char("You are now an Arch-Angel!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "pmage"     ) )

    {

    victim->class = 2;

    if ( victim->trust > 6 )

    {

    victim->trust = victim->trust;     

    }

    else

    {

    victim->trust = 6;

    }

    victim->level = 6;

    victim->pcdata->powers[MPOWER_RUNE0] = 0;

    send_to_char("You are now a purple mage!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "rmage"     ) )

    {

    victim->class = 2;

    if ( victim->trust > 6 )

    {

      victim->trust=victim->trust;

    }

    else

    {

    victim->trust = 6;

    }

    victim->level = 6;

    victim->pcdata->powers[MPOWER_RUNE0] = 1;

    send_to_char("You are now a red mage!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "ymage"     ) )

    {

    victim->class = 2;

    if ( victim->trust > 6 )

    {

    victim->trust=victim->trust;

    }

    else

    {

    victim->trust = 6;

    }

    victim->level = 6;

    victim->pcdata->powers[MPOWER_RUNE0] = 4;

    send_to_char("You are now a yellow mage!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "bmage"     ) )

    {

    victim->class = 2;

    if ( victim->trust > 6 )

    {

      victim->trust=victim->trust;

    }

    else

    {

    victim->trust = 6;

    }

    victim->level = 6;

    victim->pcdata->powers[MPOWER_RUNE0] = 2;

    send_to_char("You are now a blue mage!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "gmage"     ) )

    {

    victim->class = 2;

    if ( victim->trust > 6 )

    {

    victim->trust=victim->trust;

    }

    else

    {

    victim->trust = 6;

    }

    victim->level = 6;

    victim->pcdata->powers[MPOWER_RUNE0] = 3;

    send_to_char("You are now a green mage!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "werewolf"   ) ) 

    {

    victim->class = 4;

    victim->level = 3;

    send_to_char("You are now a werewolf!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "vampire"    ) ) 

    {

    victim->class = 8;

    victim->level = 3;

    do_generation(ch,"5");

    send_to_char("You are now a vampire!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "highlander" ) ) 

    {

    victim->class = 16;

    victim->level = 3;

    send_to_char("You are now a highlander!\n\r", victim);

    }

    else if ( !str_cmp( arg2, "ninja"      ) ) 

    {

     victim->class = 64;

     if ( victim->trust > 6 )

     {

       victim->trust=victim->trust;

     }

     else

     {

     victim->trust = 6;

     }

     victim->level = 6;

     send_to_char("You are now a ninja!\n\r", victim);

    }    

    else if ( !str_cmp( arg2, "monk"      ) ) 

    {

     victim->class = 128;

     if ( victim->trust > 6 )

     {

       victim->trust=victim->trust;

     }

     else

     {

     victim->trust = 6;

     }

     victim->level = 6;

     send_to_char("You are now a monk!\n\r", victim);

    }    

    else if ( !str_cmp( arg2, "drow"       ) ) 

    {

    victim->class = 32;

    send_to_char("You are now a drow!\n\r", victim);

    }

    else

    {

	send_to_char( "Syntax: class <char> <class>.\n\r", ch );

	send_to_char("      Classes:\n\r", ch );

    send_to_char("None, ", ch);

    send_to_char("Angel, ", ch);

    send_to_char("Arch-Angel , ", ch);

    send_to_char("Purple Mage, Blue Mage, Yellow Mage, Green Mage, Red Mage, ", ch);

    send_to_char("Werewolf, ", ch);

    send_to_char("Vampire, ", ch);

    send_to_char("Ninja, ", ch);

    send_to_char("Monk, ", ch);

    send_to_char("Highlander, ", ch);

    send_to_char("Drow, ", ch);

	return;

    }

    send_to_char("Class Set.\n\r",ch);

    return;

}

      

void do_generation( CHAR_DATA *ch, char *argument )

{

    CHAR_DATA *victim;

    int gen;

    char      arg1 [MAX_INPUT_LENGTH];

    char      arg2 [MAX_INPUT_LENGTH];

    argument = one_argument( argument, arg1 );

    argument = one_argument( argument, arg2 );

        

    if ( IS_NPC(ch) ) return;



    if ( ch->trust < 10 )

    {

	send_to_char( "Huh?\n\r", ch );

	return;

    }

    

    if ( arg1[0] == '\0' || arg2[0] == '\0' )

    {

	send_to_char( "Syntax: generation <char> <generation>.\n\r", ch );

    send_to_char("Generation 1 is a Master <Class> and 2 is clan leader.\n\r", ch);

	return;

    }

    

    if ( ( victim = get_char_room( ch, arg1 ) ) == NULL )

    {

	send_to_char( "That player is not here.\n\r", ch);

	return;

    }

    

    gen = is_number( arg2 ) ? atoi( arg2 ) : -1;



    send_to_char("Generation Set.\n\r",ch);

    victim->pcdata->stats[UNI_GEN] = gen;

    return;

}



void do_outcast( CHAR_DATA *ch, char *argument )

{

    CHAR_DATA *victim;

    char arg[MAX_INPUT_LENGTH];

    char buf[MAX_STRING_LENGTH];



    one_argument( argument, arg );



	if ( ch->pcdata->stats[UNI_GEN] != 2 &&

		   !IS_SET(ch->special, SPC_DEMON_LORD)

	       && ch->level != 6 )

	{

		send_to_char("You are not a clan leader!\n\r", ch);

		return;

	}



    if ( arg[0] == '\0' )

    {

	send_to_char( "Outcast who?\n\r", ch );

	return;

    }



    if ( ( victim = get_char_world( ch, arg ) ) == NULL )

    {

	send_to_char( "They aren't here.\n\r", ch );

	return;

    }

    

    if ( victim == ch )

    {

    send_to_char("You cannot outcast youself!\n\r", ch);

    return;

    }



    if ( IS_NPC(victim) )

    {

	send_to_char( "Not on NPC's.\n\r", ch );

	return;

    }



 if ( IS_CLASS(ch,CLASS_DEMON) && IS_SET(ch->special, SPC_DEMON_LORD)

      && IS_CLASS(victim, CLASS_DEMON) ) 

  {

  	sprintf(buf,"%s has been outcasted from Heaven", victim->name);

	do_info(victim,buf);

	  

    if (IS_VAMPAFF(victim,VAM_FANGS) )

    {

	 send_to_char("Your fangs slide back into your gums.\n\r",victim);

	 act("$N's fangs slide back into $s gums.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_FANGS);

    }

       

    if (IS_VAMPAFF(victim,VAM_CLAWS) ) 

	{

	    send_to_char("Your claws slide back under your nails.\n\r",victim);

	    act("$N's claws slide back under $s nails.", ch, NULL, victim, TO_ROOM);

	    REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CLAWS);

	}

	

    if (IS_VAMPAFF(victim,VAM_NIGHTSIGHT) )

    {

	 send_to_char("The red glow in your eyes fades.\n\r",victim);

	 act("The red glow in $N's eyes fades.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_NIGHTSIGHT);

    }

    

    if (IS_IMMUNE(victim,IMM_SHIELDED) )

    {

     send_to_char("You stop shielding your aura.\n\r",victim);

     REMOVE_BIT(victim->immune, IMM_SHIELDED);

    }

	

	if (IS_SET(victim->act, PLR_HOLYLIGHT) )

	{

	 REMOVE_BIT(victim->act, PLR_HOLYLIGHT);

	 send_to_char( "Your senses return to normal.\n\r", victim );

	}



    if (IS_DEMAFF(victim,DEM_HORNS) )

    {

	 send_to_char("Your halo dissapears.\n\r",victim);

	 act("$N's halo dissapears.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->powers[DPOWER_CURRENT], DEM_HORNS);

	}

	

	if (IS_DEMAFF(victim,DEM_HOOVES) )

    {

	send_to_char("The light around your feet vanishes.\n\r",victim);

	 act("The light around $N's feet vanishes.", ch, NULL,victim,TO_ROOM);

	 REMOVE_BIT(victim->pcdata->powers[DPOWER_CURRENT], DEM_HOOVES);

    }

    

    if (IS_DEMAFF(victim,DEM_WINGS) )

    {

	if (IS_DEMAFF(victim,DEM_UNFOLDED) )

	{

	    send_to_char("Your wings fold up behind your back.\n\r",victim);

	    act("$N's wings fold up behind $s back.", ch, NULL, victim, TO_ROOM);

	    REMOVE_BIT(victim->pcdata->powers[DPOWER_CURRENT], DEM_UNFOLDED);

	}

	send_to_char("Your wings slide into your back.\n\r",victim);

	act("$N's wings slide into $s back.", ch, NULL, victim, TO_ROOM);

	REMOVE_BIT(victim->pcdata->powers[DPOWER_CURRENT], DEM_WINGS);

    }

    

	if ( IS_EXTRA(victim, EXTRA_OSWITCH) ) 

	{

	 do_humanform(victim,"");

	}

	

	victim->pcdata->powers[DPOWER_FLAGS] = 0;

	victim->pcdata->stats[DEMON_TOTAL] = 0;

	victim->pcdata->stats[DEMON_CURRENT] = 0;

	

    free_string(victim->lord);

    victim->lord     = str_dup( "" );

    free_string(victim->clan);

    victim->clan     = str_dup( "" );



	REMOVE_BIT(victim->special, SPC_CHAMPION );

    REMOVE_BIT(victim->special, SPC_SIRE);

    REMOVE_BIT(victim->special, SPC_PRINCE);

    REMOVE_BIT(victim->special, SPC_DEMON_LORD);

    victim->pcdata->stats[UNI_RAGE] = 0;

    victim->class = 0;

	send_to_char("You have been outcasted from Heaven!\n\r", victim);

  }

  

else if ( ( IS_CLASS(ch, CLASS_MAGE) && ch->level == LEVEL_ARCHMAGE )

	        && ch->pcdata->powers[MPOWER_RUNE0] == victim->pcdata->powers[MPOWER_RUNE0]

	        && victim->level < LEVEL_ARCHMAGE )

  {

  	sprintf(buf,"%s has been outcasted from the Mages Guild.", victim->name);

	do_info(victim,buf);  	

	

	victim->trust = 0;

	victim->class = 0;

	victim->level = 3;

	send_to_char("You have been outcasted from the Mages Guild!\n\r", victim);

  }

  

else if ( IS_CLASS(ch,CLASS_VAMPIRE)

		  && !str_cmp(victim->clan,ch->clan) 

		  && IS_CLASS(victim, CLASS_VAMPIRE) )   

  {

  	sprintf(buf,"%s has been outcasted from %s.", victim->name, victim->clan);

	do_info(victim,buf);



	victim->pcdata->condition[COND_THIRST] = 10000;



	if ( IS_CLASS(victim, CLASS_VAMPIRE) ) do_unwerewolf(victim,"");

	if ( IS_VAMPAFF(victim,VAM_DISGUISED) ) do_mask(victim,"self");

	if ( IS_POLYAFF(victim,POLY_SERPENT) ) do_serpent(victim,"");

    

    if (IS_VAMPAFF(victim,VAM_FANGS) )

    {

	 send_to_char("Your fangs slide back into your gums.\n\r",victim);

	 act("$N's fangs slide back into $s gums.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_FANGS);

    }

    

    if (IS_CLASS(victim, CLASS_VAMPIRE) && IS_VAMPAFF(victim,VAM_CLAWS) ) 

	{

	    send_to_char("Your claws slide back under your nails.\n\r",victim);

	    act("$N's claws slide back under $s nails.", ch, NULL, victim, TO_ROOM);

	    REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CLAWS);

	}



    if (IS_VAMPAFF(victim,VAM_NIGHTSIGHT) )

    {

	 send_to_char("The red glow in your eyes fades.\n\r",victim);

	 act("The red glow in $N's eyes fades.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_NIGHTSIGHT);

    }

    

    if (IS_AFFECTED(victim,AFF_SHADOWSIGHT) )

    {

	 send_to_char("You can no longer see between planes.\n\r",victim);

	 REMOVE_BIT(victim->affected_by, AFF_SHADOWSIGHT);

    }

    

    if (IS_IMMUNE(victim,IMM_SHIELDED) )

    {

     send_to_char("You stop shielding your aura.\n\r",victim);

     REMOVE_BIT(victim->immune, IMM_SHIELDED);

    }

    

    if (IS_VAMPAFF(victim,VAM_DISGUISED) )

    {

     free_string( victim->morph );

     victim->morph = str_dup( victim->name );

     send_to_char("You transform into yourself.\n\r", victim);

     REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_DISGUISED);

    }

    

    if (IS_AFFECTED(victim,AFF_SHADOWPLANE) )

    {

     send_to_char("You fade back into the real world.\n\r",victim);

	 act("The shadows flicker and $N fades into existance.",ch,NULL,victim,TO_ROOM);

	 REMOVE_BIT(victim->affected_by,AFF_SHADOWPLANE);

	 do_look(victim,"auto");

	}

	

	if (IS_SET(victim->act, PLR_HOLYLIGHT) )

	{

	 REMOVE_BIT(victim->act, PLR_HOLYLIGHT);

	 send_to_char( "Your senses return to normal.\n\r", victim );

	}



	REMOVE_BIT(victim->special, SPC_INCONNU );

	REMOVE_BIT(victim->special, SPC_ANARCH );

    REMOVE_BIT(victim->special, SPC_SIRE);

    REMOVE_BIT(victim->special, SPC_PRINCE);

	REMOVE_BIT(victim->affected_by, AFF_POLYMORPH);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CHANGED);

    REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_MIST);

	REMOVE_BIT(victim->affected_by, AFF_ETHEREAL);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_FLYING);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_SONIC);

	REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_BAT);

	REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_WOLF);



	victim->pcdata->stats[UNI_RAGE] = 0;

    free_string(victim->lord);

    victim->lord     = str_dup( "" );

    free_string(victim->clan);

    victim->clan     = str_dup( "" );

    victim->pcdata->stats[UNI_GEN]     = 0;

    victim->pcdata->stats[UNI_AFF]     = 0;

    victim->pcdata->stats[UNI_CURRENT] = -1;

    victim->pcdata->rank = 0;

    victim->class = 0;

    victim->beast = 15;

    victim->pcdata->condition[COND_THIRST] = 0;

    	

	send_to_char("You have been outcasted!\n\r", victim);

  }

  

else if ( IS_CLASS(ch, CLASS_WEREWOLF) && ch->pcdata->stats[UNI_GEN] == 2

          && !str_cmp(victim->clan,ch->clan) && IS_CLASS(victim, CLASS_WEREWOLF) )

  {

  	sprintf(buf,"%s has been outcasted from %s.", victim->name, victim->clan);

	do_info(victim,buf);



	victim->pcdata->powers[WPOWER_BEAR]   = 4;

    victim->pcdata->powers[WPOWER_LYNX]   = 4;

	victim->pcdata->powers[WPOWER_BOAR]   = 4;

	victim->pcdata->powers[WPOWER_OWL]    = 4;

	victim->pcdata->powers[WPOWER_SPIDER] = 4; 

	victim->pcdata->powers[WPOWER_WOLF]   = 4;

	victim->pcdata->powers[WPOWER_HAWK]   = 4;

	victim->pcdata->powers[WPOWER_MANTIS] = 4;



	do_unwerewolf(victim,"");

    do_shift(victim,"homid");

    

    if (IS_VAMPAFF(victim,VAM_FANGS) )

    {

    	send_to_char("Your talons slide back into your fingers.\n\r",victim);

	    act("$N's talons slide back into $s fingers.",ch,NULL,victim,TO_ROOM);

    	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CLAWS);

    }



    if (IS_VAMPAFF(victim,VAM_NIGHTSIGHT) )

    {

	 send_to_char("The red glow in your eyes fades.\n\r",victim);

	 act("The red glow in $N's eyes fades.", ch, NULL, victim, TO_ROOM);

	 REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_NIGHTSIGHT);

    }

    

    if (IS_AFFECTED(victim,AFF_SHADOWSIGHT) )

    {

	 send_to_char("You can no longer see between planes.\n\r",victim);

	 REMOVE_BIT(victim->affected_by, AFF_SHADOWSIGHT);

    }

    

    if (IS_IMMUNE(victim,IMM_SHIELDED) )

    {

     send_to_char("You stop shielding your aura.\n\r",victim);

     REMOVE_BIT(victim->immune, IMM_SHIELDED);

    }



    if (IS_AFFECTED(victim,AFF_SHADOWPLANE) )

    {

     send_to_char("You fade back into the real world.\n\r",victim);

	 act("The shadows flicker and $N fades into existance.",ch,NULL,victim,TO_ROOM);

	 REMOVE_BIT(victim->affected_by,AFF_SHADOWPLANE);

	 do_look(victim,"auto");

	}

	

	if (IS_SET(victim->act, PLR_WIZINVIS) )

	{

	 REMOVE_BIT(victim->act, PLR_WIZINVIS);

	 send_to_char( "You slowly fade into existence.\n\r", victim );

	}

	

	if (IS_SET(victim->act, PLR_HOLYLIGHT) )

	{

	 REMOVE_BIT(victim->act, PLR_HOLYLIGHT);

	 send_to_char( "Your senses return to normal.\n\r", victim );

	}



	REMOVE_BIT(victim->special, SPC_INCONNU );

	REMOVE_BIT(victim->special, SPC_ANARCH );

    REMOVE_BIT(victim->special, SPC_SIRE);

    REMOVE_BIT(victim->special, SPC_PRINCE);

	REMOVE_BIT(victim->affected_by, AFF_POLYMORPH);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CHANGED);

    REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_MIST);

	REMOVE_BIT(victim->affected_by, AFF_ETHEREAL);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_FLYING);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_SONIC);

	REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_BAT);

	REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_WOLF);

	

	victim->pcdata->powers[WPOWER_BEAR]   = 0;

    victim->pcdata->powers[WPOWER_LYNX]   = 0;

	victim->pcdata->powers[WPOWER_BOAR]   = 0;

	victim->pcdata->powers[WPOWER_OWL]    = 0;

	victim->pcdata->powers[WPOWER_SPIDER] = 0; 

	victim->pcdata->powers[WPOWER_WOLF]   = 0;

	victim->pcdata->powers[WPOWER_HAWK]   = 0;

	victim->pcdata->powers[WPOWER_MANTIS] = 0;



	victim->pcdata->stats[UNI_RAGE] = 0;

    free_string(victim->lord);

    victim->lord     = str_dup( "" );

    free_string(victim->clan);

    victim->clan     = str_dup( "" );

    victim->pcdata->stats[UNI_GEN]     = 0;

    victim->pcdata->stats[UNI_AFF]     = 0;

    victim->pcdata->stats[UNI_CURRENT] = -1;

    victim->pcdata->rank = 0;

    victim->class = 0;  	

     

	send_to_char("You have been outcasted!\n\r", victim);

  }

else if ( IS_CLASS(ch, CLASS_NINJA) && ch->pcdata->stats[UNI_GEN] == 2

          && !str_cmp(victim->clan,ch->clan) && IS_CLASS(victim, CLASS_NINJA) )

  {

  	sprintf(buf,"%s has been outcasted from %s.", victim->name, victim->clan);

	do_info(victim,buf);  



    if ( IS_VAMPAFF(victim,VAM_CLAWS) ) 

	{

	 	send_to_char("You shove your iron claws up your sleeves\n\r",victim);

	    act("$N shoves $S iron claws up $e sleeves.", ch, NULL, victim, TO_ROOM);

	    REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CLAWS);

    }

	

	if (IS_SET(victim->act, PLR_WIZINVIS) )

	{

	 REMOVE_BIT(victim->act, PLR_WIZINVIS);

	 send_to_char( "You appear from the shadows.\n\r", victim );

	}

	

	if (IS_SET(victim->act, PLR_HOLYLIGHT) )

	{

	 REMOVE_BIT(victim->act, PLR_HOLYLIGHT);

	 send_to_char( "Your senses return to normal.\n\r", victim );

	}



    REMOVE_BIT(victim->special, SPC_SIRE);

    REMOVE_BIT(victim->special, SPC_PRINCE);

	REMOVE_BIT(victim->affected_by, AFF_POLYMORPH);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_CHANGED);

    REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_MIST);

	REMOVE_BIT(victim->affected_by, AFF_ETHEREAL);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_FLYING);

	REMOVE_BIT(victim->pcdata->stats[UNI_AFF], VAM_SONIC);

	REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_BAT);

	REMOVE_BIT(victim->pcdata->powers[WOLF_POLYAFF], POLY_WOLF);

	

  	victim->pcdata->powers[NPOWER_SORA]     = 0;

  	victim->pcdata->powers[NPOWER_CHIKYU]   = 0;

	victim->pcdata->powers[NPOWER_NINGENNO] = 0;



	victim->pcdata->stats[UNI_RAGE] = 0;

    free_string(victim->lord);

    victim->lord     = str_dup( "" );

    free_string(victim->clan);

    victim->clan     = str_dup( "" );

    victim->pcdata->stats[UNI_GEN]     = 0;

    victim->pcdata->stats[UNI_AFF]     = 0;

    victim->pcdata->stats[UNI_CURRENT] = -1;

    victim->pcdata->rank = 0;

    victim->class = 0;  	

    victim->trust = 0;

    victim->level = 3;

	send_to_char("You have been outcasted!\n\r", victim);

  }

else if ( IS_CLASS(ch, CLASS_DROW) && ch->pcdata->stats[UNI_GEN] == 2

          && !str_cmp(victim->clan,ch->clan) && IS_CLASS(victim, CLASS_DROW) )

  {

    sprintf(buf,"%s has been outcasted from %s.", victim->name, victim->clan);

	do_info(victim,buf);

    

    if (IS_IMMUNE(victim,IMM_SHIELDED) )

    {

     send_to_char("You stop shielding your aura.\n\r",victim);

     REMOVE_BIT(victim->immune, IMM_SHIELDED);

    }

	

	if (IS_SET(victim->act, PLR_HOLYLIGHT) || IS_SET(victim->act, PLR_DROWSIGHT) )

	{

	 REMOVE_BIT(victim->act, PLR_HOLYLIGHT);

	 REMOVE_BIT(victim->act, PLR_DROWSIGHT);

	 send_to_char( "Your senses return to normal.\n\r", victim );

	}

	

	if (IS_AFFECTED(victim, AFF_DARKNESS)) 

	{

		REMOVE_BIT(victim->affected_by, AFF_DARKNESS);

		send_to_char("The darkness around you fades away.\n\r",ch);

		return;

	}

	

	victim->pcdata->powers[1] = 0;

  

	free_string(victim->lord);

    victim->lord     = str_dup( "" );

    free_string(victim->clan);

    victim->clan     = str_dup( "" );

	REMOVE_BIT(victim->special, SPC_SIRE);

    REMOVE_BIT(victim->special, SPC_PRINCE);

    REMOVE_BIT(victim->special, SPC_ANARCH);

    REMOVE_BIT(victim->special, SPC_DROW_WAR );

    REMOVE_BIT(victim->special, SPC_DROW_MAG );

    REMOVE_BIT(victim->special, SPC_DROW_CLE );

    victim->pcdata->stats[UNI_RAGE] = 0;

    victim->class = 0; 

	send_to_char("You have been outcasted!\n\r", victim);

  }

  else

  	send_to_char("They are not of your clan!\n\r", ch);

  return;

}  



void do_autostance( CHAR_DATA *ch, char *argument )

{

	char arg       [MAX_INPUT_LENGTH];	

	int selection;

	

	one_argument( argument, arg );



    if (IS_NPC(ch)) return;  

	

    if (!str_cmp(arg,"none")    ) 

    {

    selection = STANCE_NONE;

	send_to_char("You're autostance has been removed.\n\r",ch);

	REMOVE_BIT(ch->extra, EXTRA_STANCE);

	}

    else if (!str_cmp(arg,"viper")   ) 

    {

    selection = STANCE_VIPER;

	send_to_char("Viper stance set.\n\r",ch);

	}

    else if (!str_cmp(arg,"crane")   ) 

    {

    selection = STANCE_CRANE;

	send_to_char("Crane stance set.\n\r",ch);

	}

    else if (!str_cmp(arg,"crab")    ) 

    {

    selection = STANCE_CRAB;

	send_to_char("Crab stance set.\n\r",ch);

	}

    else if (!str_cmp(arg,"mongoose")) 

    {

    selection = STANCE_MONGOOSE;

	send_to_char("Mongoose stance set.\n\r",ch);

	}

    else if (!str_cmp(arg,"bull")    ) 

    {

    selection = STANCE_BULL;

	send_to_char("Bull stance set.\n\r",ch);

	}

    else

    {

	if (!str_cmp(arg,"mantis") && ch->stance[STANCE_CRANE] >= 200 &&

	    ch->stance[STANCE_VIPER] >= 200)

	{

	    selection = STANCE_MANTIS;

	    send_to_char("Mantis stance set.\n\r",ch);

	}

	else if (!str_cmp(arg,"dragon") && ch->stance[STANCE_BULL] >= 200 &&

	    ch->stance[STANCE_CRAB] >= 200)

	{

	    selection = STANCE_DRAGON;

	    send_to_char("Dragon stance set.\n\r",ch);

	}

	else if (!str_cmp(arg,"tiger") && ch->stance[STANCE_BULL] >= 200 &&

	    ch->stance[STANCE_VIPER] >= 200)

	{

	    selection = STANCE_TIGER;

	    send_to_char("Tiger stance set.\n\r",ch);

	}

	else if (!str_cmp(arg,"monkey") && ch->stance[STANCE_CRANE] >= 200 &&

	    ch->stance[STANCE_MONGOOSE] >= 200)

	{

	    selection = STANCE_MONKEY;

	    send_to_char("Monkey stance set.\n\r",ch);

	}

	else if (!str_cmp(arg,"swallow") && ch->stance[STANCE_CRAB] >= 200 &&

	    ch->stance[STANCE_MONGOOSE] >= 200)

	{

	    selection = STANCE_SWALLOW;

	    send_to_char("Swallow  stance set.\n\r",ch);

	}

	else

	{

	    send_to_char("Syntax is: autostance <style>.\n\r",ch);

	    send_to_char("Autotance being one of: None, Viper, Crane, Crab, Mongoose, Bull.\n\r",ch);

	    send_to_char("                        Mantis, Dragon, Tiger, Monkey, Swallow.\n\r",ch);

	    return;

	}

    }

    ch->stance[11] = selection;

    SET_BIT(ch->extra, EXTRA_STANCE);

    return;

}



void do_stances( CHAR_DATA *ch, char *argument )

{

    char arg[MAX_INPUT_LENGTH];



    one_argument( argument, arg );



	send_to_char("Stance:      Skill\n\r", ch);

    

    if ( arg[0] == '\0' )

    {

	show_stance(ch,1);

	show_stance(ch,2);

	show_stance(ch,3);

	show_stance(ch,4);

	show_stance(ch,5);

	show_stance(ch,6);

	show_stance(ch,7);

	show_stance(ch,8);

	show_stance(ch,9);

	show_stance(ch,10);

    }

    else if (!str_cmp(arg,"viper"))    show_stance(ch,1);

    else if (!str_cmp(arg,"crane"))    show_stance(ch,2);

    else if (!str_cmp(arg,"crab"))     show_stance(ch,3);

    else if (!str_cmp(arg,"mongoose")) show_stance(ch,4);

    else if (!str_cmp(arg,"bull"))     show_stance(ch,5);

    else if (!str_cmp(arg,"mantis"))   show_stance(ch,6);

    else if (!str_cmp(arg,"dragon"))   show_stance(ch,7);

    else if (!str_cmp(arg,"tiger"))    show_stance(ch,8);

    else if (!str_cmp(arg,"monkey"))   show_stance(ch,9);

    else if (!str_cmp(arg,"swallow"))  show_stance(ch,10);   

    else send_to_char("You know of no such stance.\n\r",ch);

    return;

}



void show_stance( CHAR_DATA *ch, int stance )

{

    char buf[MAX_INPUT_LENGTH];

    char bufskill[MAX_INPUT_LENGTH];



    if (IS_NPC(ch)) return;



         if (ch->stance[stance] <= 1  ) sprintf(bufskill,"Apprentice");

    else if (ch->stance[stance] <= 26 ) sprintf(bufskill,"Trainee");

    else if (ch->stance[stance] <= 51 ) sprintf(bufskill,"Student");

    else if (ch->stance[stance] <= 76 ) sprintf(bufskill,"Fairly experienced");

    else if (ch->stance[stance] <= 101) sprintf(bufskill,"Well trained");

    else if (ch->stance[stance] <= 126) sprintf(bufskill,"Highly skilled");

    else if (ch->stance[stance] <= 151) sprintf(bufskill,"Expert");

    else if (ch->stance[stance] <= 176) sprintf(bufskill,"Master");

    else if (ch->stance[stance] <= 200) sprintf(bufskill,"Grand master");

    else if (ch->stance[stance] >= 201) sprintf(bufskill,"Legendary master");

    else return;

    if      (stance == 1)

	sprintf(buf,"Viper:    %s\n\r",bufskill);

    else if (stance == 2)

	sprintf(buf,"Crane:    %s\n\r",bufskill);

    else if (stance == 3)

	sprintf(buf,"Crab:     %s\n\r",bufskill);

    else if (stance == 4)

	sprintf(buf,"Bull:     %s\n\r",bufskill);

    else if (stance == 5)

	sprintf(buf,"Mongoose: %s\n\r",bufskill);

    else if (stance == 6)

	sprintf(buf,"Mantis:   %s\n\r",bufskill);

    else if (stance == 7)

	sprintf(buf,"Dragon:   %s\n\r",bufskill);

    else if (stance == 8)

	sprintf(buf,"Tiger:    %s\n\r",bufskill);

    else if (stance == 9)

	sprintf(buf,"Monkey:   %s\n\r",bufskill);

    else if (stance == 10)

	sprintf(buf,"Swallow:  %s\n\r",bufskill);

    else return;

    send_to_char(buf,ch);

    return;

}



void do_weapons( CHAR_DATA *ch, char *argument )

{

    char arg[MAX_INPUT_LENGTH];



    one_argument( argument, arg );



	send_to_char("Weapon:      Skill\n\r", ch);

    

    if ( arg[0] == '\0' )

    {

    show_weapons(ch,0);

	show_weapons(ch,1);

	show_weapons(ch,2);

	show_weapons(ch,3);

	show_weapons(ch,4);

	show_weapons(ch,5);

	show_weapons(ch,6);

	show_weapons(ch,7);

	show_weapons(ch,8);

	show_weapons(ch,9);

	show_weapons(ch,10);

	show_weapons(ch,11);

	show_weapons(ch,12);

    }

    else if (!str_cmp(arg,"unarm") || !str_cmp(arg,"unarmed"))    show_weapons(ch,0);

    else if (!str_cmp(arg,"slice"))    show_weapons(ch,1);

    else if (!str_cmp(arg,"stab"))     show_weapons(ch,2);

    else if (!str_cmp(arg,"slash"))    show_weapons(ch,3);

    else if (!str_cmp(arg,"whip"))     show_weapons(ch,4);

    else if (!str_cmp(arg,"claw"))     show_weapons(ch,5);

    else if (!str_cmp(arg,"blast"))    show_weapons(ch,6);

    else if (!str_cmp(arg,"pound"))    show_weapons(ch,7);

    else if (!str_cmp(arg,"crush"))    show_weapons(ch,8);

    else if (!str_cmp(arg,"grep"))     show_weapons(ch,9);

    else if (!str_cmp(arg,"bite"))     show_weapons(ch,10);    

    else if (!str_cmp(arg,"pierce"))   show_weapons(ch,11);

    else if (!str_cmp(arg,"suck"))     show_weapons(ch,12);   

    else send_to_char("You know of no such weapon.\n\r",ch);

    return;

}



void show_weapons( CHAR_DATA *ch, int weapon )

{

    char buf[MAX_INPUT_LENGTH];

    char bufskill[MAX_INPUT_LENGTH];



    if (IS_NPC(ch)) return;



         if (ch->wpn[weapon] <= 1   ) sprintf(bufskill,"Slightly skilled");

    else if (ch->wpn[weapon] <= 26  ) sprintf(bufskill,"Reasonable");

    else if (ch->wpn[weapon] <= 51  ) sprintf(bufskill,"Fairly competent");

    else if (ch->wpn[weapon] <= 76  ) sprintf(bufskill,"Highly skilled");

    else if (ch->wpn[weapon] <= 101 ) sprintf(bufskill,"Very dangerous");

    else if (ch->wpn[weapon] <= 126 ) sprintf(bufskill,"Extremely deadly");

    else if (ch->wpn[weapon] <= 151 ) sprintf(bufskill,"An expert");

    else if (ch->wpn[weapon] <= 176 ) sprintf(bufskill,"A master");

    else if (ch->wpn[weapon] <= 200 ) sprintf(bufskill,"A grand master");

    else if (ch->wpn[weapon] >= 201 ) sprintf(bufskill,"Supremely skilled");

    else return;

    if      (weapon == 0)

	sprintf(buf,"Unarmed:   %s\n\r",bufskill);

    else if (weapon == 1)

	sprintf(buf,"Slice:     %s\n\r",bufskill);

    else if (weapon == 2)

	sprintf(buf,"Stab:      %s\n\r",bufskill);

    else if (weapon == 3)

	sprintf(buf,"Slash:     %s\n\r",bufskill);

    else if (weapon == 4)

	sprintf(buf,"Whip:      %s\n\r",bufskill);

    else if (weapon == 5)

	sprintf(buf,"Claw:      %s\n\r",bufskill);

    else if (weapon == 6)

	sprintf(buf,"Blast:     %s\n\r",bufskill);

    else if (weapon == 7)

	sprintf(buf,"Pound:     %s\n\r",bufskill);

    else if (weapon == 8)

	sprintf(buf,"Crush:     %s\n\r",bufskill);

    else if (weapon == 9)

	sprintf(buf,"Grep:      %s\n\r",bufskill);

    else if (weapon == 10)

	sprintf(buf,"Bite:      %s\n\r",bufskill);

    else if (weapon == 11)

	sprintf(buf,"Pierce:    %s\n\r",bufskill);

    else if (weapon == 12)

	sprintf(buf,"Suck:      %s\n\r",bufskill);

    else return;

    send_to_char(buf,ch);

    return;

}



/* 

 * Donate Command

 */

void do_donate(CHAR_DATA *ch, char *argument)

{

 char Object_Name[MAX_INPUT_LENGTH];

 ROOM_INDEX_DATA *xRoom;

 OBJ_DATA *xObject;

 int DONATION_ROOM;



 argument = one_argument(argument, Object_Name);

 if ( Object_Name == '\0' )

 {

   send_to_char("Donate WHAT Object?",ch);

   return;  

 }

 if ( ( xObject= get_obj_carry(ch,Object_Name)) == NULL)

 {

   send_to_char("You can't donate that item! You have not got it!",ch);

   return;

 }

 if ( ( xObject->pIndexData->vnum >= 3700  && xObject->pIndexData->vnum <= 3704 )

        || xObject->pIndexData->vnum == 3716)

 {

   send_to_char("We don't want puny newbie equipment!\n\r", ch);

   return;

 }

 if ( xObject->pIndexData->vnum == 30000 )

 {

   send_to_char("We don't take soul blades!\n\r", ch);

   return;

 }

 if (xObject->questowner != NULL && strlen(xObject->questowner) > 1)

 {

   send_to_char("We don't take claimed equipment, it might be stolen!\n\r", ch);

   return;

 } 

 /* Actually, some KaVir things are good - Loki

 if ( xObject->pIndexData->vnum >= 30000  && xObject->pIndexData->vnum <= 30040 )

 {

   send_to_char("We don't want any KaVir stuff!\n\r", ch);

   return;

 }

 */

 switch(xObject->item_type)

 {

   case ITEM_WEAPON :

       DONATION_ROOM=DONATION_ROOM_WEAPON;

       break;   

   case ITEM_ARMOR  :

       DONATION_ROOM=DONATION_ROOM_ARMOR;

       break;   

   default :

       DONATION_ROOM=DONATION_ROOM_REST;

       break;   

 }

 if ( ( xRoom = get_room_index(DONATION_ROOM)) == NULL)

 {

   bug("Donate Room Does Not Exist : %d",DONATION_ROOM);

   return;

 }

 act("$p vanishes from your hands in a pink mist.",ch,xObject,NULL,TO_CHAR);

 send_to_char("You are rewarded 50 gold for you donation.\n\r", ch);

 ch->gold += 50;

 act("$p vanishes from $n's hands in a pink mist.",ch,xObject,NULL,TO_ROOM);

 obj_from_char(xObject);

 obj_to_room(xObject,xRoom);

 act("$p appears in a pink mist in the room.",ch,xObject,NULL,TO_ROOM);

 return;

}



void do_version( CHAR_DATA *ch, char *argument)

{

   char buf[MAX_INPUT_LENGTH];



   sprintf(buf, "\n\r**********************************\n\rRealms of Elkor :- %d.%d\n\r**********************************\n\r",VERSION_NUMBER,VERSION_NUMBER2);

   send_to_char(buf,ch);

   return;

}



void mage_regen( CHAR_DATA *ch )

{

    int min = 5;

    int max = 10;



    if (IS_NPC(ch)) return;



	min += 10;

	min += 20;

	max += 20;

	max += 30;

    	ch->mana = UMIN(ch->mana + number_range(min,max), ch->max_mana);

	if ( ch->mana >= ch->max_mana )

	    send_to_char("Your spell casting abilities are at full potential.\n\r",ch);

    return;

}



void do_clans( CHAR_DATA *ch, char *argument )

{

    do_help( ch, "clans" );

    return;

}



void do_affects( CHAR_DATA *ch, char *argument )

{

	if ( IS_NPC(ch) ) return;

	

	send_to_char("You are affected by:\n\r", ch);

	

	if ( IS_AFFECTED(ch, AFF_INVISIBLE) )

	send_to_char("Invisibility\n\r", ch);

	if ( IS_AFFECTED(ch, AFF_HIDE) )

	send_to_char("Hidden\n\r", ch );

	if ( IS_AFFECTED(ch, AFF_CHARM) ) 

	send_to_char("Charmed\n\r", ch);

    if ( IS_AFFECTED(ch, AFF_PASS_DOOR) )

    send_to_char("Pass Door\n\r", ch );

    if ( IS_AFFECTED(ch, AFF_ETHEREAL) )

    send_to_char("Ethereal\n\r", ch);

    if ( IS_AFFECTED(ch, AFF_FAERIE_FIRE) )

    send_to_char("Fairie Fire\n\r", ch);

    if ( IS_AFFECTED(ch, AFF_SANCTUARY) ) 

    send_to_char("Sanctuary\n\r", ch);

    if ( IS_AFFECTED(ch, AFF_STEELSHIELD) )

    send_to_char("Steel Shield\n\r", ch);

    

	if ( IS_ITEMAFF(ch, ITEMA_SHOCKSHIELD) ) 

	send_to_char("Electrical Shield\n\r", ch);

	if ( IS_ITEMAFF(ch, ITEMA_FIRESHIELD) ) 

	send_to_char("Fire Shield\n\r", ch);

	if ( IS_ITEMAFF(ch, ITEMA_ICESHIELD) ) 

	send_to_char("Ice Shield\n\r", ch);

	if ( IS_ITEMAFF(ch, ITEMA_ACIDSHIELD) ) 

	send_to_char("Acid Shield\n\r", ch);

	if ( IS_ITEMAFF(ch, ITEMA_CHAOSSHIELD) ) 

	send_to_char("Chaos Shield\n\r", ch);

	if ( IS_ITEMAFF(ch, ITEMA_REFLECT) ) 

	send_to_char("Reflecting Shield\n\r", ch);

	send_to_char("\n\r", ch);

    

    return;

}

 

