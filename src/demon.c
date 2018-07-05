          
          
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
          
          /*
           * Local functions.
           */
          
          void do_inpart( CHAR_DATA *ch, char *argument )
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
           
          
              if (!IS_CLASS(ch, CLASS_DEMON) || !IS_SET(ch->special, SPC_DEMON_LORD))
              {
          	if (!IS_SET(ch->special, SPC_CHAMPION) || !IS_SET(ch->special, SPC_PRINCE))
          	{
          	    send_to_char("Huh?\n\r",ch);
          	    return;
          	}
              }
          
              if ( arg1[0] == '\0' || arg2[0] == '\0' )
              {
          	send_to_char( "Syntax: Inpart <person> <power>\n\r", ch );
          	send_to_char("Halo (2500), HolyFeet (2500), Nightsight (2500), Toughness (7500), Speed (7500),\n\r",ch);
          	send_to_char("Wings (2500), Might (7500), Travel (500),\n\r",ch);
          	send_to_char("Scry (7500), Shadowsight (7500), Move (500), Leap (500), Magic (500),\n\r",ch);
          	send_to_char("Truesight (7500), Mask (7500), Sweep (7500), Shield (7500).\n\r",ch);
          	send_to_char("Lifespan (0), Pact (0), Angel (0), Longsword (0), Shortsword (0).\n\r", ch );
          	return;
              }
          
              if ( ( victim = get_char_world( ch, arg1 ) ) == NULL )
              {
          	send_to_char( "Nobody by that name.\n\r", ch );
          	return;
              }
          
              if ( IS_NPC(victim) )
              {
          	send_to_char( "Not on NPC's.\n\r", ch );
          	return;
              }
          
              if ( victim != ch && str_cmp(victim->lord, ch->name) && 
          	str_cmp(victim->lord, ch->lord) && strlen(victim->lord) > 1 )
              {
          	send_to_char( "They are not your guardian angel.\n\r", ch );
          	return;
              }
          
              if (!str_cmp(arg2,"pact"))
              {
          	if (victim == ch)
          	{
          	    send_to_char("Not on yourself!\n\r",ch);
          	    return;
          	}
          	if(IS_IMMORTAL(victim))
          	{
          		send_to_char("Not on an Immortal.\n\r", ch);
          		return;
          	}
          	if (IS_SET(victim->special,SPC_SIRE))
          	{
          	    send_to_char("You have lost the power to make pacts!\n\r",victim);
          	    send_to_char("You remove their power to make pacts.\n\r",ch);
          	    REMOVE_BIT(victim->special, SPC_SIRE);
          	}
          	else
          	{
          	    send_to_char("You have been granted the power to make pacts!\n\r",victim);
          	    send_to_char("You grant them the power to make pacts.\n\r",ch);
          	    SET_BIT(victim->special, SPC_SIRE);
          	}
          	save_char_obj(victim);
          	return;
              }
          
              if (!str_cmp(arg2,"prince"))
              {
          	if (victim == ch)
          	{
          	    send_to_char("Not on yourself!\n\r",ch);
          	    return;
          	}
          	if (!IS_CLASS(ch, CLASS_DEMON))
          	{
          	    send_to_char("Only the Arch-Angel has the power to make princes.\n\r",ch);
          	    return;
          	}
          	if (IS_SET(victim->special,SPC_PRINCE))
          	{
          	    send_to_char("You have lost your angelhood!\n\r",victim);
          	    send_to_char("You remove their angelhood.\n\r",ch);
          	    REMOVE_BIT(victim->special, SPC_PRINCE);
          	}
          	else
          	{
          	    send_to_char("You have been made a full angel!\n\r",victim);
          	    send_to_char("You make them a prince.\n\r",ch);
          	    SET_BIT(victim->special, SPC_PRINCE);
          	}
          	save_char_obj(victim);
          	return;
              }
          
              if (!str_cmp(arg2,"longsword"))
              {
          	send_to_char("You have been granted the power to transform into an angelic longsword!\n\r",victim);
          	send_to_char("You grant them the power to transform into an angelic longsword.\n\r",ch);
          	victim->pcdata->powers[DPOWER_OBJ_VNUM] = 29662;
          	save_char_obj(victim);
          	return;
              }
          
              if (!str_cmp(arg2,"shortsword"))
              {
          	send_to_char("You have been granted the power to transform into an angelic shortsword!\n\r",victim);
          	send_to_char("You grant them the power to transform into an angelic shortsword.\n\r",ch);
          	victim->pcdata->powers[DPOWER_OBJ_VNUM] = 29663;
          	save_char_obj(victim);
          	return;
              }
          
            if (!str_cmp(arg2,"halo")) 
          	{inpart = DEM_HORNS; cost = 2500;}    
              else if (!str_cmp(arg2,"nightsight")) 
          	{inpart = DEM_EYES; cost = 2500;}
              else if (!str_cmp(arg2,"wings")) 
          	{inpart = DEM_WINGS; cost = 2500;}
              else if (!str_cmp(arg2,"might")) 
          	{inpart = DEM_MIGHT; cost = 7500;}
              else if (!str_cmp(arg2,"toughness")) 
          	{inpart = DEM_TOUGH; cost = 7500;}
              else if (!str_cmp(arg2,"speed"))
          	{inpart = DEM_SPEED; cost = 7500;}
              else if (!str_cmp(arg2,"travel")) 
          	{inpart = DEM_TRAVEL; cost = 500;}
          	else if (!str_cmp(arg2, "truesight"))
          	{ inpart = DEM_TRUESIGHT; cost = 7500;}
			else if (!str_cmp(arg2, "shield"))
          	{ inpart = DEM_SHIELD; cost = 7500;}
              else if (!str_cmp(arg2,"scry"))
          	{inpart = DEM_SCRY; cost = 7500;}
              else if (!str_cmp(arg2,"shadowsight")) 
          	{inpart = DEM_SHADOWSIGHT; cost = 7500;}
              else if (!str_cmp(arg2,"move")) 
          	{inpart = DEM_MOVE; cost = 500;}
              else if (!str_cmp(arg2,"leap")) 
          	{inpart = DEM_LEAP; cost = 500;}
              else if (!str_cmp(arg2,"magic")) 
          	{inpart = DEM_MAGIC; cost = 500;}
              else if (!str_cmp(arg2,"lifespan")) 
          	{inpart = DEM_LIFESPAN; cost = 0;}
          	else if (!str_cmp(arg2,"mask")) 
          	{inpart = DEM_MASK; cost = 7500;}
          	else if (!str_cmp(arg2,"sweep")) 
          	{inpart = DEM_TAIL; cost = 7500;}
			else if (!str_cmp(arg2,"holyfeet")) 
          	{inpart = DEM_HOOVES; cost = 2500;}
          	else
              {
          	send_to_char("Please select a power from:\n\r",ch);
          	send_to_char( "Syntax: Inpart <person> <power>\n\r", ch );
          	send_to_char("Halo (2500), HolyFeet (2500), Nightsight (2500), Toughness (7500), Speed (7500),\n\r",ch);
          	send_to_char("Wings (2500), Might (7500), Travel (500),\n\r",ch);
          	send_to_char("Scry (7500), Shadowsight (7500), Move (500), Leap (500), Magic (500),\n\r",ch);
          	send_to_char("Truesight (7500), Mask (7500) Sweep (7500) Shield (7500).\n\r",ch);
          	send_to_char("Lifespan (0), Pact (0), Angel (0), Longsword (0), Shortsword (0).\n\r", ch );
          	return;
              }
              if (IS_DEMPOWER(victim, inpart))
              {
          	send_to_char("They have already got that power.\n\r",ch);
          	return;
              }
              if (ch->pcdata->stats[DEMON_TOTAL] < cost || 
          	ch->pcdata->stats[DEMON_CURRENT] < cost)
              {
          	send_to_char("You have insufficient power to inpart that gift.\n\r",ch);
          	return;
              }
              SET_BIT(victim->pcdata->powers[DPOWER_FLAGS], inpart);
              ch->pcdata->stats[DEMON_TOTAL]   -= cost;
              ch->pcdata->stats[DEMON_CURRENT] -= cost;
              if (victim != ch) send_to_char("You have been granted an angelic gift from your patron!\n\r",victim);
              send_to_char("Ok.\n\r",ch);
              if (victim != ch) save_char_obj(ch);
              save_char_obj(victim);
              return;
          }
          
          void do_demmask( CHAR_DATA *ch, char *argument )
          {
              CHAR_DATA *victim;
              char      arg [MAX_INPUT_LENGTH];
              char      buf [MAX_INPUT_LENGTH];
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_CLASS(ch, CLASS_DEMON))
              {
          	send_to_char( "Huh?\n\r", ch );
          	return;
              }
          
          	if (!IS_DEMPOWER( ch, DEM_MASK))
              {
          	send_to_char("You haven't been granted the gift of mask.\n\r",ch);
          	return;
              }
          
          	if ( arg[0] == '\0' )
              {
          	send_to_char( "Change to look like whom?\n\r", ch );
          	return;
              }
          
              if (IS_AFFECTED(ch,AFF_POLYMORPH) && !IS_VAMPAFF(ch,VAM_DISGUISED))
              {
          	send_to_char( "Not while polymorphed.\n\r", ch );
          	return;
              }
          
              if ( ( victim = get_char_room( ch, arg ) ) == NULL )
              {
          	send_to_char( "They aren't here.\n\r", ch );
          	return;
              }
          
              if ( IS_IMMORTAL(victim) && victim != ch )
              {
          	send_to_char( "You can only mask avatars or lower.\n\r", ch );
          	return;
              }
          
              ch->pcdata->condition[COND_THIRST] -= number_range(30,40);
          
              if ( ch == victim )
              {
          	if (!IS_AFFECTED(ch,AFF_POLYMORPH) && !IS_VAMPAFF(ch,VAM_DISGUISED))
          	{
          	    send_to_char( "You already look like yourself!\n\r", ch );
          	    return;
          	}
          	sprintf(buf,"Your form shimmers and transforms into %s.",ch->name);
          	act(buf,ch,NULL,victim,TO_CHAR);
          	sprintf(buf,"%s's form shimmers and transforms into %s.",ch->morph,ch->name);
          	act(buf,ch,NULL,victim,TO_ROOM);
          	REMOVE_BIT(ch->affected_by, AFF_POLYMORPH);
          	REMOVE_BIT(ch->pcdata->stats[UNI_AFF], VAM_DISGUISED);
              	free_string( ch->morph );
              	ch->morph = str_dup( "" );
          	return;
              }
              if (IS_VAMPAFF(ch,VAM_DISGUISED))
              {
              	sprintf(buf,"Your form shimmers and transforms into a clone of %s.",victim->name);
              	act(buf,ch,NULL,victim,TO_CHAR);
              	sprintf(buf,"%s's form shimmers and transforms into a clone of %s.",ch->morph,victim->name);
              	act(buf,ch,NULL,victim,TO_NOTVICT);
              	sprintf(buf,"%s's form shimmers and transforms into a clone of you!",ch->morph);
              	act(buf,ch,NULL,victim,TO_VICT);
              	free_string( ch->morph );
              	ch->morph = str_dup( victim->name );
          	return;
              }
              sprintf(buf,"Your form shimmers and transforms into a clone of %s.",victim->name);
              act(buf,ch,NULL,victim,TO_CHAR);
              sprintf(buf,"%s's form shimmers and transforms into a clone of %s.",ch->name,victim->name);
              act(buf,ch,NULL,victim,TO_NOTVICT);
              sprintf(buf,"%s's form shimmers and transforms into a clone of you!",ch->name);
              act(buf,ch,NULL,victim,TO_VICT);
              SET_BIT(ch->affected_by, AFF_POLYMORPH);
              SET_BIT(ch->pcdata->stats[UNI_AFF], VAM_DISGUISED);
              free_string( ch->morph );
              ch->morph = str_dup( victim->name );
              return;
          }
          
void do_tail( CHAR_DATA *ch, char *argument )
{
    char      arg [MAX_INPUT_LENGTH];

    argument = one_argument( argument, arg );

    if (IS_NPC(ch)) return;

    if (!IS_CLASS(ch, CLASS_DEMON) && !IS_SET(ch->special, SPC_CHAMPION))
    {
	send_to_char("Huh?\n\r",ch);
	return;
    }
    if (!IS_DEMPOWER( ch, DEM_TAIL))
    {
	send_to_char("You haven't been granted the gift to sweep.\n\r",ch);
	return;
    }

	if (IS_DEMAFF(ch,DEM_TAIL) )
    {
	send_to_char("You won't sweep people in combat anymore.\n\r",ch);
	REMOVE_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_TAIL);
	return;
    }
    send_to_char("You will sweep people in combat.\n\r",ch);
    SET_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_TAIL);
    return;
}

		  
		  void do_blackdemonarmour( CHAR_DATA *ch, char *argument )
          {
              OBJ_INDEX_DATA *pObjIndex;
              OBJ_DATA *obj;
              char arg[MAX_INPUT_LENGTH];
              int vnum = 0;
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_CLASS(ch, CLASS_DEMON))
              {
          	if (!IS_SET(ch->special, SPC_CHAMPION) || !IS_SET(ch->special, SPC_PRINCE))
          	{
          	    send_to_char("Huh?\n\r",ch);
          	    return;
          	}
              }
          
              if (arg[0] == '\0')
              {
          	send_to_char("Please specify which piece of white angel armor you wish to make:\n\nRing, Collar, Plate, Helmet, Leggings, Boots, Gauntlets, Sleeves, Cape, Belt, Bracer or Visor.\n\r",ch);
          	return;
              }
              if      (!str_cmp(arg,"ring"     )) vnum = 29650;
              else if (!str_cmp(arg,"collar"   )) vnum = 29651;
              else if (!str_cmp(arg,"plate"    )) vnum = 29652;
              else if (!str_cmp(arg,"helmet"   )) vnum = 29653;
              else if (!str_cmp(arg,"leggings" )) vnum = 29654;
              else if (!str_cmp(arg,"boots"    )) vnum = 29655;
              else if (!str_cmp(arg,"gauntlets")) vnum = 29656;
              else if (!str_cmp(arg,"sleeves"  )) vnum = 29657;
              else if (!str_cmp(arg,"cape"     )) vnum = 29658;
              else if (!str_cmp(arg,"belt"     )) vnum = 29659;
              else if (!str_cmp(arg,"bracer"   )) vnum = 29660;
              else if (!str_cmp(arg,"visor"    )) vnum = 29661;
              else
              {
          	send_to_char("Please specify which piece of white angel armor you wish to make:\n\nRing, Collar, Plate, Helmet, Leggings, Boots, Gauntlets, Sleeves, Cape, Belt, Bracer, or Visor.\n\r",ch);
          	return;
              }
              if ( ch->pcdata->stats[DEMON_TOTAL] < 5000 || ch->pcdata->stats[DEMON_CURRENT] < 5000)
              {
          	send_to_char("It costs 5000 points of power to create a piece of white angel armour.\n\r",ch);
          	return;
              }
              if ( vnum == 0 || (pObjIndex = get_obj_index( vnum )) == NULL)
              {
          	send_to_char("Missing object, please inform Elkor.\n\r",ch);
          	return;
              }
              ch->pcdata->stats[DEMON_TOTAL]   -= 5000;
              ch->pcdata->stats[DEMON_CURRENT] -= 5000;
              obj = create_object(pObjIndex, 50);
              obj_to_char(obj, ch);
              act("$p appears in your hands in a blast of white light.",ch,obj,NULL,TO_CHAR);
              act("$p appears in $n's hands in a blast of white light.",ch,obj,NULL,TO_ROOM);
              return;
          }
          void do_reddemonarmour( CHAR_DATA *ch, char *argument )
          {
              OBJ_INDEX_DATA *pObjIndex;
              OBJ_DATA *obj;
              char arg[MAX_INPUT_LENGTH];
              int vnum = 0;
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_CLASS(ch, CLASS_DEMON))
              {
          	if (!IS_SET(ch->special, SPC_CHAMPION) || !IS_SET(ch->special, SPC_PRINCE))
          	{
          	    send_to_char("Huh?\n\r",ch);
          	    return;
          	}
              }
          
              if (arg[0] == '\0')
              {
          	send_to_char("Please specify which piece of blue angel armor you wish to make:\n\nRing, Collar, Plate, Helmet, Leggings, Boots, Gauntlets, Sleeves, Cape, Belt, Bracer or Visor.\n\r",ch);
          	return;
              }
          	if (!str_cmp(arg,"ring"          )) vnum = 29664;
              else if (!str_cmp(arg,"collar"   )) vnum = 29665;
              else if (!str_cmp(arg,"plate"    )) vnum = 29666;
              else if (!str_cmp(arg,"helmet"   )) vnum = 29667;
              else if (!str_cmp(arg,"leggings" )) vnum = 29668;
              else if (!str_cmp(arg,"boots"    )) vnum = 29669;
              else if (!str_cmp(arg,"gauntlets")) vnum = 29670;
              else if (!str_cmp(arg,"sleeves"  )) vnum = 29671;
              else if (!str_cmp(arg,"cape"     )) vnum = 29672;
              else if (!str_cmp(arg,"belt"     )) vnum = 29673;
              else if (!str_cmp(arg,"bracer"   )) vnum = 29674;
              else if (!str_cmp(arg,"visor"    )) vnum = 29675;
              else
              {
          	send_to_char("Please specify which piece of blue angel armor you wish to make:\n\nRing, Collar, Plate, Helmet, Leggings, Boots, Gauntlets, Sleeves, Cape, Belt, Bracer, or Visor.\n\r",ch);
          	return;
              }
          	if ( ch->pcdata->stats[DEMON_TOTAL] < 10000 || ch->pcdata->stats[DEMON_CURRENT] < 10000)
              {
          	send_to_char("It costs 10000 points of power to create a piece of blue angel armour.\n\r",ch);
          	return;
              }
              if ( vnum == 0 || (pObjIndex = get_obj_index( vnum )) == NULL)
              {
          	send_to_char("Missing object, please inform Elkor.\n\r",ch);
          	return;
              }
              ch->pcdata->stats[DEMON_TOTAL]   -= 10000;
              ch->pcdata->stats[DEMON_CURRENT] -= 10000;
              obj = create_object(pObjIndex, 50);
              obj_to_char(obj, ch);
              act("$p appears in your hands in a blast of blue light.",ch,obj,NULL,TO_CHAR);
              act("$p appears in $n's hands in a blast of blue light.",ch,obj,NULL,TO_ROOM);
              return;
          }
          
          void do_travel( CHAR_DATA *ch, char *argument )
          {
              char      arg [MAX_INPUT_LENGTH];
              CHAR_DATA *victim;
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (IS_CLASS(ch, CLASS_DEMON) || IS_SET(ch->special, SPC_CHAMPION))
              {
          	if (!IS_DEMPOWER( ch, DEM_TRAVEL))
          	{
          	    send_to_char("You haven't been granted the gift of travel.\n\r",ch);
          	    return;
          	}
              }
              else
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
          
          
              if ( ( victim = get_char_world( ch, arg ) ) == NULL )
              {
          	send_to_char( "Nobody by that name.\n\r", ch );
          	return;
              }
          
              if ( IS_NPC(victim) )
              {
          	send_to_char( "Not on NPC's.\n\r", ch );
          	return;
              }
          
              if ( ch == victim )
              {
                  send_to_char( "That might be a bit tricky...\n\r", ch );
                  return;
              }
          
              if ( victim->level != LEVEL_AVATAR || 
          	(!IS_SET(victim->special, SPC_CHAMPION) && !IS_CLASS(victim, CLASS_DEMON)))
              {
          	send_to_char( "Nothing happens.\n\r", ch );
          	return;
              }
          /*
              if ( IS_CLASS(victim, CLASS_DEMON) && str_cmp(ch->lord, victim->name) )
              {
          	send_to_char( "Nothing happens.\n\r", ch );
          	return;
              }
              else if ( IS_SET(victim->special, SPC_CHAMPION) &&
          	(str_cmp(victim->lord, ch->name) && str_cmp(victim->lord, ch->lord) ))
              {
          	send_to_char( "Nothing happens.\n\r", ch );
          	return;
              }
          */
              if (victim->in_room == NULL)
              {
          	send_to_char( "Nothing happens.\n\r", ch );
          	return;
              }
          
              if ( victim->position != POS_STANDING )
              {
          	send_to_char( "You are unable to focus on their location.\n\r", ch );
          	return;
              }
          
              send_to_char("You glow bright blue for a moment then vanish.\n\r",ch);
              act("$n glows bright blue for a moment then vanishes.",ch,NULL,NULL,TO_ROOM);
              char_from_room(ch);
              char_to_room(ch,victim->in_room);
              do_look(ch,"");
              act("You appear in front of $N in a flash of blue light!\n\r",ch,NULL, victim, TO_CHAR);
              act("$n appears in front of you in a flash of blue light!\n\r",ch,NULL, victim, TO_VICT);
              act("$n appears in front of $N in a flash of blue light!",ch,NULL, victim, TO_NOTVICT);
              return;
          }
          
          void do_horns( CHAR_DATA *ch, char *argument )
          {
              char      arg [MAX_INPUT_LENGTH];
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_CLASS(ch, CLASS_DEMON) && !IS_SET(ch->special, SPC_CHAMPION))
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
              if (!IS_DEMPOWER( ch, DEM_HORNS))
              {
          	send_to_char("You haven't been granted the gift of a halo.\n\r",ch);
          	return;
              }
          
              if (IS_DEMAFF(ch,DEM_HORNS) )
              {
          	send_to_char("Your halo dissapears.\n\r",ch);
          	act("$n's halo dissapears.", ch, NULL, NULL, TO_ROOM);
          	REMOVE_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_HORNS);
          	return;
              }
              send_to_char("Light surrounds you and a halo appears on top of your head.\n\r",ch);
              act("Light surrounds $n and a halo appears on $n's head.", ch, NULL, NULL, TO_ROOM);
              SET_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_HORNS);
              return;
          }
          
          void do_hooves( CHAR_DATA *ch, char *argument )
          {
              char      arg [MAX_INPUT_LENGTH];
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_CLASS(ch, CLASS_DEMON))
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
              if (!IS_DEMPOWER( ch, DEM_HOOVES))
              {
          	send_to_char("You haven't been granted the gift of holyfeet.\n\r",ch);
          	return;
              }
          
              if (IS_DEMAFF(ch,DEM_HOOVES) )
              {
          	send_to_char("The light around your feet vanishes.\n\r",ch);
          	act("The light around $n's feet vanishes.", ch, NULL,NULL,TO_ROOM);
          	REMOVE_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_HOOVES);
          	return;
              }
              send_to_char("A bright white light surrounds your feet.\n\r",ch);
              act("A bright white light surrounds $n's feet.", ch, NULL, NULL, TO_ROOM);
              SET_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_HOOVES);
              return;
          }
		  
		  void do_wings( CHAR_DATA *ch, char *argument )
          {
              char      arg [MAX_INPUT_LENGTH];
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_CLASS(ch, CLASS_DEMON) && !IS_SET(ch->special, SPC_CHAMPION))
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
              if (!IS_DEMPOWER( ch, DEM_WINGS))
              {
          	send_to_char("You haven't been granted the gift of wings.\n\r",ch);
          	return;
              }
          
              if (arg[0] != '\0')
              {
          	if (!IS_DEMAFF(ch,DEM_WINGS) )
          	{
          	    send_to_char("First you better get your wings out!\n\r",ch);
          	    return;
          	}
          	if (!str_cmp(arg,"unfold") || !str_cmp(arg,"u"))
          	{
          	    if (IS_DEMAFF(ch,DEM_UNFOLDED) )
          	    {
          		send_to_char("But your wings are already unfolded!\n\r",ch);
          		return;
          	    }
          	    send_to_char("Your wings unfold from behind your back.\n\r",ch);
          	    act("$n's wings unfold from behind $s back.", ch, NULL, NULL, TO_ROOM);
          	    SET_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_UNFOLDED);
          	    return;
          	}
          	else if (!str_cmp(arg,"fold") || !str_cmp(arg,"f"))
          	{
          	    if (!IS_DEMAFF(ch,DEM_UNFOLDED) )
          	    {
          		send_to_char("But your wings are already folded!\n\r",ch);
          		return;
          	    }
          	    send_to_char("Your wings fold up behind your back.\n\r",ch);
          	    act("$n's wings fold up behind $s back.", ch, NULL, NULL, TO_ROOM);
          	    REMOVE_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_UNFOLDED);
          	    return;
          	}
          	else
          	{
          	    send_to_char("Do you want to FOLD or UNFOLD your wings?\n\r",ch);
          	    return;
          	}
              }
          
              if (IS_DEMAFF(ch,DEM_WINGS) )
              {
          	if (IS_DEMAFF(ch,DEM_UNFOLDED) )
          	{
          	    send_to_char("Your wings fold up behind your back.\n\r",ch);
          	    act("$n's wings fold up behind $s back.", ch, NULL, NULL, TO_ROOM);
          	    REMOVE_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_UNFOLDED);
          	}
          	send_to_char("Your wings slide into your back.\n\r",ch);
          	act("$n's wings slide into $s back.", ch, NULL, NULL, TO_ROOM);
          	REMOVE_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_WINGS);
          	return;
              }
              send_to_char("Your wings extend from your back.\n\r",ch);
              act("A pair of wings extend from $n's back.", ch, NULL, NULL, TO_ROOM);
              SET_BIT(ch->pcdata->powers[DPOWER_CURRENT], DEM_WINGS);
              return;
          }
          
          void do_lifespan( CHAR_DATA *ch, char *argument )
          {
              char      arg [MAX_INPUT_LENGTH];
              OBJ_DATA *obj;
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_CLASS(ch,CLASS_DEMON) && !IS_SET(ch->special,SPC_CHAMPION))
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
          
              if (!IS_DEMPOWER( ch, DEM_LIFESPAN))
              {
          	send_to_char("You haven't been granted the gift of lifespan.\n\r",ch);
          	return;
              }
          
              if ( ( obj = ch->pcdata->chobj ) == NULL )
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
          
              if ( obj->chobj == NULL || obj->chobj != ch )
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
          
              if (!IS_HEAD(ch,LOST_HEAD))
              {
          	send_to_char("You cannot change your lifespan in this form.\n\r",ch);
          	return;
              }
          
                   if (!str_cmp(arg,"l") || !str_cmp(arg,"long" )) obj->timer = 0;
              else if (!str_cmp(arg,"s") || !str_cmp(arg,"short")) obj->timer = 1;
              else
              {
          	send_to_char("Do you wish to have a long or short lifespan?\n\r",ch);
          	return;
              }
              send_to_char("Ok.\n\r",ch);
          
              return;
          }
          
          void do_pact( CHAR_DATA *ch, char *argument )
          {
              CHAR_DATA *victim;
              char      arg [MAX_INPUT_LENGTH];
              bool      can_sire = FALSE;
          
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_CLASS(ch, CLASS_DEMON) && !IS_SET(ch->special, SPC_CHAMPION))
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
          
              if (IS_CLASS(ch, CLASS_DEMON)) can_sire = TRUE;
              else if (IS_SET(ch->special,SPC_SIRE)) can_sire = TRUE;
              else can_sire = TRUE;
          
              if (!can_sire)
              {
          	send_to_char("You are not able to make a pact.\n\r",ch);
          	return;
              }
          
              if (!str_cmp(ch->lord,"") && !IS_CLASS(ch, CLASS_DEMON))
              {
          	send_to_char( "First you must find an Arch-Angel.\n\r", ch );
          	return;
              }
          
              if ( arg[0] == '\0' )
              {
          	send_to_char( "Make a pact with whom?\n\r", ch );
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
          	send_to_char( "You cannot make a pact with yourself.\n\r", ch );
          	return;
              }
          
              if (victim->alignment <= 900)
              {
          	  send_to_char("You cannot pact anyone who is not angelic!\n\r",ch);
          	  return;
              }
			  
			  if (IS_CLASS(victim, CLASS_MAGE))
              {
          	send_to_char( "You cannot make a pact with a mage.\n\r", ch );
          	return;
              }
          
              if ( victim->level != LEVEL_AVATAR && !IS_IMMORTAL(victim) )
              {
          	send_to_char( "You can only make pacts with avatars.\n\r", ch );
          	return;
              }
          
              if (!IS_IMMUNE(victim,IMM_DEMON))
              {
          	send_to_char( "You cannot make a pact with an unwilling person.\n\r", ch );
          	return;
              }
          
              if (IS_CLASS(victim, CLASS_DEMON) || IS_SET(victim->special, SPC_CHAMPION))
              {
          	send_to_char("They have already been blessed!\n\r",ch);
          	return;
              }
          
              if ( IS_CLASS(victim, CLASS_HIGHLANDER) )
              {
          	send_to_char( "You cannot make a pact with a highlander.\n\r", ch );
          	return;
              }
          
              if (ch->exp < 777)
              {
          	  send_to_char("You cannot afford the 777 exp to make a pact.\n\r",ch);
          	  return;
              }
          
              ch->exp = ch->exp - 777;
              act("You make $N a guardian angel!", ch, NULL, victim, TO_CHAR);
              act("$n makes $N a guardian angel!", ch, NULL, victim, TO_NOTVICT);
              act("$n makes you a guardian angel!", ch, NULL, victim, TO_VICT);
              victim->class=0;
              victim->class=CLASS_DEMON;
              free_string(victim->lord);
			  victim->lord = str_dup(ch->name);
			  free_string(victim->clan);
              victim->clan=str_dup(ch->clan);
			  victim->damcap[0] = 2750;
			  victim->damcap[1] = 2750;
			  victim->special=0;
              SET_BIT(victim->special, SPC_CHAMPION);
          
              if (IS_CLASS(victim, CLASS_VAMPIRE)) do_mortalvamp(victim,"");
              REMOVE_BIT(victim->act, PLR_HOLYLIGHT);
              REMOVE_BIT(victim->act, PLR_WIZINVIS);
              REMOVE_BIT(victim->special, SPC_SIRE);
              REMOVE_BIT(victim->special, SPC_ANARCH);
              victim->pcdata->stats[UNI_RAGE] = 0;
          
              free_string(victim->morph);
              victim->clan=str_dup("");
              free_string(victim->clan);
              victim->clan=str_dup("");
              free_string(victim->lord);
              if (IS_CLASS(ch,CLASS_DEMON)) victim->lord=str_dup(ch->name);
              else victim->lord=str_dup(ch->lord);
          
              if (!str_cmp(ch->name,"galin"))
			  {
			  free_string(victim->lord);
    	      victim->lord = str_dup(ch->name);
			  victim->clan = str_dup(ch->clan);
			  }
			  
			  else if (!str_cmp(ch->name,"icecreampimp"))
			  {
		      free_string(victim->lord);
    	      victim->lord = str_dup(ch->name);
			  victim->clan = str_dup(ch->clan);
			  }
			  
			  else if (!str_cmp(ch->name,"robert"))
			  {
		      free_string(victim->lord);
    	      victim->lord = str_dup(ch->name);
			  victim->clan = str_dup(ch->clan);
			  }
			  
			  else if (!str_cmp(ch->name,"veldran"))
			  {
		      free_string(victim->lord);
    	      victim->lord = str_dup(ch->name);
			  victim->clan = str_dup(ch->clan);
			  }

			  save_char_obj(ch);
              save_char_obj(victim);
              return;
          }
          
          void do_offersoul( CHAR_DATA *ch, char *argument )
          {
              char      arg [MAX_INPUT_LENGTH];
              argument = one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
          
              if (!IS_IMMUNE(ch, IMM_DEMON))
              {
          /*
          	send_to_char("That would be a very bad idea...\n\r",ch);
          	return;
          */
          	send_to_char("You will now allow angels to bless your soul.\n\r",ch);
          	SET_BIT(ch->immune, IMM_DEMON);
          	return;
            
              }
              send_to_char("You will no longer allow angels to bless your soul.\n\r",ch);
              REMOVE_BIT(ch->immune, IMM_DEMON);
              return;
          }
          
          void do_weaponform( CHAR_DATA *ch, char *argument )
          {
              OBJ_DATA *obj;
              if (IS_NPC(ch)) return;
              if (!IS_CLASS(ch, CLASS_DEMON) && !IS_SET(ch->special, SPC_CHAMPION))
              {
          	send_to_char( "Huh?\n\r", ch);
          	return;
              }
              else if (IS_AFFECTED(ch,AFF_POLYMORPH))
              {
          	send_to_char( "You cannot do this while polymorphed.\n\r", ch);
          	return;
              }
              if (ch->pcdata->powers[DPOWER_OBJ_VNUM] < 1)
              {
          	send_to_char( "You don't have the ability to change into a weapon.\n\r", ch);
          	return;
              }
              if ((obj = create_object(get_obj_index(ch->pcdata->powers[DPOWER_OBJ_VNUM]),60)) == NULL)
              {
          	send_to_char( "You don't have the ability to change into a weapon.\n\r", ch);
          	return;
              }
              if (IS_AFFECTED(ch,AFF_WEBBED))
              {
          	send_to_char( "Not with all this sticky webbing on.\n\r", ch);
          	return;
              }
              obj_to_room(obj,ch->in_room);
              act("$n transforms into $p and falls to the ground.",ch,obj,NULL,TO_ROOM);
              act("You transform into $p and fall to the ground.",ch,obj,NULL,TO_CHAR);
              ch->pcdata->obj_vnum = ch->pcdata->powers[DPOWER_OBJ_VNUM];
              obj->chobj = ch;
              ch->pcdata->chobj = obj;
              SET_BIT(ch->affected_by, AFF_POLYMORPH);
              SET_BIT(ch->extra, EXTRA_OSWITCH);
              free_string(ch->morph);
              ch->morph = str_dup(obj->short_descr);
              return;
          }
          
          void do_humanform( CHAR_DATA *ch, char *argument )
          {
              OBJ_DATA *obj;
          
              if (IS_NPC(ch)) return;
              if ( ( obj = ch->pcdata->chobj ) == NULL )
              {
          	send_to_char("You are already in human form.\n\r",ch);
          	return;
              }
          
              ch->pcdata->obj_vnum = 0;
              obj->chobj = NULL;
              ch->pcdata->chobj = NULL;
              REMOVE_BIT(ch->affected_by, AFF_POLYMORPH);
              REMOVE_BIT(ch->extra, EXTRA_OSWITCH);
              free_string(ch->morph);
              ch->morph = str_dup("");
              act("$p transforms into $n.",ch,obj,NULL,TO_ROOM);
              act("You reform your human body.",ch,obj,NULL,TO_CHAR);
              extract_obj(obj);
              if (ch->in_room->vnum == ROOM_VNUM_IN_OBJECT)
              {
          	char_from_room(ch);
          	char_to_room(ch,get_room_index(ROOM_VNUM_HELL));
              }
              return;
          }
          
          void do_champions( CHAR_DATA *ch, char *argument )
          {
              char buf[MAX_STRING_LENGTH];
              char arg[MAX_INPUT_LENGTH];
              char lord[MAX_INPUT_LENGTH];
              CHAR_DATA *gch;
          
              one_argument( argument, arg );
          
              if (IS_NPC(ch)) return;
              if (!IS_CLASS(ch, CLASS_DEMON) && !IS_SET(ch->special, SPC_CHAMPION) )
              {
          	send_to_char("Huh?\n\r",ch);
          	return;
              }
          
              if (strlen(ch->lord) < 2 && !IS_CLASS(ch, CLASS_DEMON) )
              {
          	send_to_char("But you don't follow any angel!\n\r",ch);
          	return;
              }
          
              if (IS_CLASS(ch, CLASS_DEMON)) strcpy(lord,ch->name);
          	else strcpy(lord,ch->lord);
              sprintf( buf, "The angels of %s:\n\r", lord );
              send_to_char( buf, ch );
              send_to_char("[      Name      ] [ Hits ] [ Mana ] [ Move ] [  Exp  ] [       Power        ]\n\r", ch );
              for ( gch = char_list; gch != NULL; gch = gch->next )
              {
          	if ( IS_NPC(gch) ) continue;
          	if ( !IS_CLASS(gch, CLASS_DEMON) && !IS_SET(gch->special, SPC_CHAMPION) ) 
          	    continue;
          	if ( !str_cmp(ch->lord,lord) || !str_cmp(ch->name,lord))
          	{
          	    sprintf( buf,
          	    "[%-16s] [%-6d] [%-6d] [%-6d] [%7d] [ %-9d%9d ]\n\r",
          		capitalize( gch->name ),
          		gch->hit,gch->mana,gch->move,
          		gch->exp, gch->pcdata->stats[DEMON_CURRENT], gch->pcdata->stats[DEMON_TOTAL]);
          		send_to_char( buf, ch );
          	}
              }
              return;
          }
          
          void do_eyespy( CHAR_DATA *ch, char *argument )
          {
              CHAR_DATA *victim;
              CHAR_DATA *familiar;
          
              if (IS_HEAD(ch,LOST_EYE_L) && IS_HEAD(ch,LOST_EYE_R))
              {
          	send_to_char( "But you don't have any more eyes to pluck out!\n\r", ch );
          	return;
              }
              if (!IS_HEAD(ch,LOST_EYE_L) && number_range(1,2) == 1)
              {
          	act( "You pluck out your left eyeball and throw it to the ground.", ch, NULL, NULL, TO_CHAR );
          	act( "$n plucks out $s left eyeball and throws it to the ground.", ch, NULL, NULL, TO_ROOM );
              }
              else if (!IS_HEAD(ch,LOST_EYE_R))
              {
          	act( "You pluck out your right eyeball and throw it to the ground.", ch, NULL, NULL, TO_CHAR );
          	act( "$n plucks out $s right eyeball and throws it to the ground.", ch, NULL, NULL, TO_ROOM );
              }
              else
              {
          	act( "You pluck out your left eyeball and throw it to the ground.", ch, NULL, NULL, TO_CHAR );
          	act( "$n plucks out $s left eyeball and throws it to the ground.", ch, NULL, NULL, TO_ROOM );
              }
              if ( ( familiar = ch->pcdata->familiar ) != NULL ) 
              {
          	make_part(ch,"eyeball");
          	return;
              }
          
              victim = create_mobile( get_mob_index( MOB_VNUM_EYE ) );
              if (victim == NULL)
              {send_to_char("Error -- please inform Elkor.\n\r",ch); return;}
          
              char_to_room( victim, ch->in_room );
          
              ch->pcdata->familiar = victim;
              victim->wizard = ch;
              return;
          }
          
          
