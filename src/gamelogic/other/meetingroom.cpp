//==============================================================================
//Copyright 2003-2012 Robert Pelloni.
//All Rights Reserved.
//==============================================================================



#include "../../main.h"



//========================================================
//MeetingRoom
//========================================================
void bobsgame_MISCMeetingRoom_Map_Load_Function()
{

}

void bobsgame_MISCMeetingRoom_Map_Run_Function(int MAP_just_loaded)
{
	if(MAP_just_loaded==1)
	{

	}


	static NPC* EXEC_npc = NULL;
	static NPC* BOB_npc = NULL;


	if(EXEC_npc==NULL)
	{
		NPC_create_npc_xy_feet(&EXEC_npc,GFX_ADULT_bigwig,16,40,15*8,14*8);
		EXEC_npc->layer=2;
		EXEC_npc->non_walkable=1;
		NPC_animate_stand_dir(&EXEC_npc,DOWN);
	}

	if(BOB_npc==NULL)
	{
		NPC_create_npc_xy_feet(&BOB_npc,GFX_ADULT_bob,16,40,15*8,20*8);
		BOB_npc->layer=2;
		BOB_npc->non_walkable=1;
		NPC_animate_stand_dir(&BOB_npc,UP);
	}





		if(GLOBAL_text_engine_state==0&&BUTTON_A_PRESSED)
		{

				TEXT_set_sprite_window(0,BOB_npc,NULL);
				TEXT_set_sprite_window(1,PLAYER_npc,NULL);



				TEXT_window(

							"<0>Five days ago...<.>"
							"I had revealed the <RED>TRUTH<WHITE> about <GREEN>bobsgame.com<WHITE>.<.>"
							"Providing <RED>definitive proof<WHITE> that absolutely could not have been faked,<.>"
							"<GREEN>\"bob\"<WHITE> convinced the internet that his campaign was nothing more than an <RED>elaborate viral advertisement<WHITE>.<.>"
							"It was OBVIOUS- it had all been <RED>planned<WHITE> from the very start!<.>"
							"\"bob\" had been <RED>acting<WHITE> for months, hiding messages on his <RED>own site!<WHITE><.>"
							"There was no <RED>conspiracy<WHITE>, it was just an <RED>act<WHITE> of feigned madness.<.>"
							"<PURPLE>Yuu<WHITE> realized that <GREEN>\"bob\"<WHITE> was never insane. He was no <RED>villanous madman<WHITE>. It was just a joke, all along!<.>"
							"Yes, <PURPLE>Yuu<WHITE> had become completely convinced.<.>"
							"What a clever advertisement! He sure had us all fooled! I can't wait to play <GREEN>\"bob's game!\"<WHITE><.>"
							"And <PURPLE>Yuu<WHITE> began to wonder,<PAUSE><NEXTLINE>\"What exactly is going on here?!\""


							/*
							"I have now proven to you beyond the shadow of a doubt that <GREEN>bobsgame.com<WHITE> is a viral advertisement and nothing more.<.>"

							"To even have jokingly considered the most remote possibility that there was ever even the tiniest hint of any kind of conspiracy to expose is complete and utter madness.<.>"
							"It was unspeakably foolish of me to even pretend that Nintendo was being controlled. Nothing could be further from the truth.<.>"
							"Anyone that ever says anything otherwise is clearly completely insane and should not be given the slightest amount of credibility.<.>"

							"In fact, I have come to realize that <GREEN>\"bob's game\"<WHITE> is hopelessly inferior to all Nintendo products, which are infinitely superior to all.<.>"
							"May the glorious Nintendo reign forever supreme <PAUSE><NEXTLINE>as the Greatest Company In The Universe.<.>"
							*/




							//"<0> blah.<.>"

							//"<1>One year ago..<PAUSE><NEXTLINE><.>"
							/*"I finally had a chance to meet them.<PAUSE><NEXTLINE>"

							//"Those <RED>people I admired <WHITE>who <GREEN>believed in the power of games.<WHITE><.>"



							"<RED>NINTENDO.<WHITE><.>"

							"That day, I discovered the utopia <RED>didn't exist.<WHITE><.>"

							"Everything I believed in.. Everything I had worked for had been taken away, <RED>shattered <WHITE>in an instant.<.>"

							"I had been lied to- deceived!<PAUSE><NEXTLINE>"
							"Not once or twice... <PAUSE><NEXTLINE>"
							"but for my <RED>entire life!<WHITE><.>"

							"Worse yet, I had been banished from the industry I had tried so hard to become a part of.<.>"
							"<RED>Outcast..<WHITE><PAUSE> for asking too many questions- for coming too close to the <RED>TRUTH.<WHITE><.>"
							"My dreams had been crushed, and for what?<PAUSE><NEXTLINE>"
							"For taking it seriously. For believing what they said.<.>"
							//"For expecting them to live up to what they had always stood for.<PAUSE><NEXTLINE>
							"How was I to know?<.>"

*/





							/*"I had to prove Nintendo was stopping my game. Holding it back <RED>because it wasn't shovelware.<WHITE><.>"
							"Not a <RED>single person there<WHITE> would stand up for what they claimed they stood for.<.>"
							"It was true. It WAS just a lie.<.>"




							"I had uncovered a <RED>CONSPIRACY<WHITE> in the video game industry!<.>"
							"An <RED>EVIL SCHEME<WHITE> devised by a ruthless organization,<.>"
							"designed to ensure that <RED>GOOD GAMES<WHITE> would never reach the market again!<.>"
							"The <RED>NINTENDO<WHITE> that we all loved and grew up with- they were behind it all!<.>"
							"The <RED>SOFTWARE KINGDOM<WHITE> was just another heartless business. They might as well have been selling life insurance.<.>"
							"Shutting out innovation to keep development costs down, all the while telling their fans they cared.<.>"
							"They didn't care about us. They didn't care about games.<.>"
							"All they cared about was keeping control over the market.<.>"
							"And so it began..<PAUSE><NEXTLINE>"


							"For months, the words from the meeting ran through my head.<PAUSE><NEXTLINE>"
							"<RED>\"I suggest that you figure out what you're going to do.\"<WHITE><.>"


							"So I did exactly that- I came up with a plan.<PAUSE><NEXTLINE>I would <RED>expose their lies<WHITE>!<.>"
							"I would show the entire world the <RED>TRUTH<WHITE> about their beloved <RED>NINTENDO.<WHITE><.>"





							"I released a video on the internet, <RED>calling for publishers<WHITE> for my game. <PAUSE>"
							"And indeed, the publishers came- 12 of them- and yet all 12 were <RED>denied.<WHITE><.>"


							//"Then I cast a spotlight on the licensing process.<.>"
							//"Everyone would see just how heartless they really were.<.>"



							"I held a <RED>protest<WHITE>, throwing myself before the mercy of <RED>NINTENDO<WHITE> in front of the entire world.<.>"



							//"If a man in the middle was stopping me, I'd go to the top.<PAUSE><NEXTLINE>"
							//"I thought.. Maybe it was just this one man- and someone there would care!<.>"
							"Of course, my pleas were ignored... and finally <RED>dismissed.<WHITE><PAUSE><NEXTLINE>"





							//"It was hard to believe. I had admired Nintendo for my entire life.<.>"
							//"The <RED>super developers<WHITE> who crafted games like works of art from their very souls.<.>"
							//"An oasis of talent- A utopia of passionate game developers who understood what games really meant.<.>"
							//"But that utopia didn't exist. It was just a fairy tale, a marketing slogan.<.>"
							//"Worse yet, I had been banished from the industry I had tried so hard to become a part of.<.>"
							//"<RED>Outcast..<WHITE><PAUSE> for asking too many questions- for coming too close to the <RED>TRUTH.<WHITE><.>"
							//"I didn't want to believe it.<.>"



							//"I still couldn't accept it.<.>"
							"I had seen it with my own eyes, but... I still.<PAUSE> <NEXTLINE><RED>NINTENDO...<WHITE> <PAUSE>Why?<.>"
							"There's no way this was the real <RED>NINTENDO!<WHITE><PAUSE><NEXTLINE>It couldn't be!<.>"

							"At that moment, it hit me.<PAUSE><NEXTLINE>"
							"I finally understood<PAUSE> <NEXTLINE><RED><HUGE>THE REAL TRUTH...<WHITE><NORMAL><.>"
							"Suddenly, it was clear. <.>That <RED>wasn't the real NINTENDO!<WHITE><.><RED><HUGE>THEY WERE IMPOSTERS!<WHITE><NORMAL><.>"
							"It all made perfect sense! The clues were there all along!<.>"
							"The employees had been <RED>warning us for years<WHITE>, hiding messages in their own games!<.>"
							"It was no coincidence. It was OBVIOUS! <PAUSE>The software kingdom had become <RED>INFILTRATED<WHITE> by the <RED>DARKNESS OF SHOVELWARE!<WHITE><.>"
							"<RED>REGGIE<WHITE> was being <RED>CONTROLLED<WHITE>, his mind hopelessly <RED>WEAKENED<WHITE> by an overload of Imaginez games!<.>"
							"He had become <RED>CORRUPTED<WHITE>, an <RED>EVIL DOUBLE<WHITE> of the REAL <RED>REGGIE.<WHITE><.>"
							//"Unknown to even his closest employees, the man known as <RED>Reggie<WHITE> had been <RED>POSSESSED<WHITE> by the <RED>EVIL POWER<WHITE> of <RED>SHOVELWARE!<WHITE><.>"
							"Even worse... It dawned on me. The man behind it all. That grinning figure in the shadows that rarely spoke. It was definitely him.<.>"
							"Yes, <RED>NINTENDO<WHITE> was being CONTROLLED by none other than... <PAUSE><NEXTLINE><HUGE><RED>MIYAMOTO!<WHITE><NORMAL><.>"

							"I knew then that it was up to me. <NEXTLINE><RED>I had to save the software kingdom.<WHITE><.>"
							"I had no choice. This was <RED>FATE.<WHITE><PAUSE><NEXTLINE>"
							"For I held the <GREEN>only weapon<WHITE> with the power to defeat this <RED>evil<WHITE>-<PAUSE><NEXTLINE>"

							"<GREEN><HUGE>The greatest game ever made.<WHITE><NORMAL><.>"


							"Even armed with this <GREEN><HUGE><NEXTLINE>LEGENDARY SUPERGAME<NORMAL><NEXTLINE><WHITE> I knew it wouldnt be easy.<.>"
							"I was facing an army- the millions of <RED>brainwashed children<WHITE>, held captive under the <RED>spell of tyranny<WHITE> cast by the <RED>diabolical sorcerer Miyamoto<WHITE>.<.>"
							"I would be demonized and hated, attacked from all sides... <RED>Persecuted<WHITE> by the very victims I was trying to save!<.>"

							"They would call me <RED>insane<WHITE>, a <RED>madman<WHITE>.<.>"
							"I would become a villain to both the <RED>game industry<WHITE> and the unsuspecting <RED>fans themselves<WHITE>- but I had no choice.<.>"
							"It was a necessary means to an end.. In time, they would all see the <RED>HORRIBLE TRUTH<WHITE> about their beloved <RED>GANTENDO!<WHITE><.>"


							"I abandoned my former identity, cast away my possessions- and began anew.<.>"
							"A madman I would become... A <RED>metamorphosis<WHITE> into a <RED>supervillain<WHITE>!<.>"

							//<change sprite to supervillain bob>

							"So my quest began, to defeat the <RED>EVIL GANTENDO<WHITE>- to expose the <RED>CORRUPTED DARK REGGIE<WHITE> and break the spell of tyranny cast by the <RED>DIABOLICAL MIYAMOTO<WHITE>!<.>"
							"I began with a vicious attack on the <RED>very source of the EVIL<WHITE>- the <RED>NINTENDO WORLD STORE<WHITE>. I sent a message to those <RED>CORRUPTED<WHITE> by the <RED>DARKNESS of SHOVELWARE<WHITE>.<.>"

							"<GREEN><HUGE>THE GREATEST GAME EVER MADE<WHITE><NORMAL> CANNOT be stopped!<.>"

							"I knew exactly what I had to do.<.>I would hold an <RED>INTERDIMENSIONAL TOURNAMENT<WHITE> gathering each and every brainwashed gamer together at once.<.>"
							"I would use that chance to break the spell over every gamer on the planet simultaneously!<.>"
							"My plan could not fail. <PAUSE><NEXTLINE><RED>GANTENDO HAD TO BE STOPPED!<WHITE><.>"*/





							/*"<0>HOLD ON A SECOND!<.>"

							"Did <PURPLE>Yuu<WHITE> really not get it yet?<PAUSE><NEXTLINE>"
							"I've been telling <PURPLE>Yuu<WHITE> from the very beginning!<PAUSE><NEXTLINE>"
							"In fact, <PURPLE>Yuu<WHITE> has been playing it all along!<.>"

							//welcome to bob's game! thank yuu for playing!


							"<GREEN>\"bob's game\"<WHITE> is not what <PURPLE>Yuu<WHITE> might think.<PAUSE><NEXTLINE>"
							"There's a <RED>reason<WHITE> it's called that.<.>"

							"<HUGE><GREEN>\"bob's game\"<WHITE> <PAUSE><NEXTLINE>"
							"is a game<PAUSE><NEXTLINE>"
							"     <RED>about a game<WHITE><PAUSE><NEXTLINE>"
							"called <GREEN>\"bob's game!\"<WHITE><NORMAL><.>"

							"<HUGE>The <RED>bottom screen<WHITE> <NEXTLINE><PAUSE>IS <NEXTLINE><PAUSE><GREEN>\"bob's game!\"<WHITE><NORMAL><.>"


							"It's <RED>the story of a young independent developer<WHITE> named <GREEN>\"bob\"<WHITE>, who has <RED>created a game<WHITE> and <RED>struggles to get it published<WHITE> in a cold industry.<.>"

							"He discovers a <RED>dark secret-<WHITE> the industry doesn't want new ideas.<PAUSE><NEXTLINE>"
							"It's a carefully controlled business model, and <RED>real innovation poses a threat<WHITE>.<.>"

							"To most video game companies, it's <RED>far more profitable<WHITE> to keep churning out <RED>bad sequels<WHITE> and movie franchise spinoffs.<.>"

							"Of course, this is all <RED>just in the game.<WHITE> I'm sure it's not <RED>really<WHITE> like that...<.>"

							"Anyway, the <RED>Nintendo<WHITE> inside of <GREEN>\"bob's game\"<WHITE> has taken control of the video game market.<.>"
							"They've become <RED>corrupt<WHITE>, and no longer focus on driving innovation.<.>"

							"Instead, they use that control to hold back any games that might <RED>compete with theirs<WHITE>.<.>"
							"They could keep selling the same games forever, only as long as there was <RED>never anything new<WHITE>.<.>"

							"Nothing like the real <RED>Nintendo<WHITE>, of course.<.>"

							"A developer <RED>obsessed with games<WHITE>, <GREEN>\"bob\"<WHITE> refused to accept this was how things really were. It contradicted everything he believed in!<.>"
							"He never thought that <RED>Nintendo<WHITE> would be like that. Afterall, they were the <RED>only ones<WHITE> making the really great games.<.>"

							"He simply couldn't believe it. In hopeless denial, <GREEN>\"bob\"<WHITE> went <RED>completely mad<WHITE> trying to convince himself it wasn't true.<.>"

							"The only explanation was that <RED>Nintendo<WHITE> had been <RED>compromised<WHITE> by an <RED>evil force<WHITE>.<.>"
							"He thought- That wasn't the real <RED>Nintendo<WHITE>. It had to be an evil replacement- <GRAY>GANTENDO-<WHITE> and it was up to him to save them.<.>"

							"Yes, <GREEN>\"bob\"<WHITE> had cracked. He truly believed that <GRAY>GANTENDO<WHITE> fans had all fallen under the spell of the <RED>diabolical Miyamoto<WHITE>.<.>"

							"In his mind, he was a <GREEN>hero<WHITE>.<PAUSE><NEXTLINE>"
							"He would <RED>break the spell of shovelware<WHITE>, and bring <GRAY>GANTENDO<WHITE> back to its senses.<.>"


							"But to <PURPLE>Yuu<WHITE>, <GREEN>\"bob\"<WHITE> had become <RED>completely insane<WHITE>- a villainous madman that delusionally believed he was on a crusade for justice.<.>"

							"Bringing down the \"<RED>evil Nintendo?<WHITE>\" Is he serious?!<PAUSE>"

							"<1><HUGE>I will destroy <PURPLE>Yuu<WHITE>, <GRAY>GANTENDO!<WHITE> <NEXTLINE>I am a <GREEN>GENIUS!<NORMAL><WHITE><.><CLOSE1>"

							"<CLEAR>And Yuu began to wonder-<.>"
							"\"Does he think he's <RED>playing some kind of game?<WHITE> That's ridiculous!\"<PAUSE><NEXTLINE>"

							"<GREEN><HUGE>And it was.<NORMAL><WHITE><.>"

							"Of course to this, <GREEN>\"bob\"<WHITE> replied-<PAUSE>"
							"<1><HUGE>\"They brainwashed <PURPLE>Yuu!<WHITE> Can't <PURPLE>Yuu<WHITE> see it?! <NEXTLINE>I'm a <GREEN>hero!<WHITE><NORMAL>\"<.><CLOSE1>"

							"<0><CLEAR>But <PURPLE>Yuu<WHITE> knew he was no hero-<PAUSE><NEXTLINE>"//-<PAUSE> or so <PURPLE>Yuu<WHITE> thought.<.>"




							"because <PURPLE>Yuu<WHITE> was the <PURPLE>true hero<WHITE> all along.<.>"

							"Legend has it that <PURPLE>Yuu<WHITE> was <RED>born<WHITE> with a <GRAY>Gantendo<WHITE> <GRAY>GameToy<WHITE> in his hands.<PAUSE><NEXTLINE>"
							"Yes- <PURPLE>Yuu<WHITE> was the legendary <NEXTLINE><PURPLE>GAME BOY<WHITE> - <PURPLE>the player of truth<WHITE>.<.>"



							//what are the batteries for?

							//"okay look. i kind of feel bad for Yuu. i'll tell Yuu what. beat me at TETRID and i'll give Yuu my BS. It's my sister's anyway."



							"It is now up to <PURPLE>Yuu<WHITE> to stop the completely insane, outcast villain developer known as <GREEN>\"bob\"<WHITE> by <RED>beating him at his own game.<WHITE><.>"


							"<1><HUGE><PURPLE>Yuu<WHITE> cannot stop me!<NORMAL><.><CLOSE1>"



							"<0>Just.. Ignore him.<.>"
							"In <GREEN>\"bob's game\"<WHITE><.>"

							"<PURPLE>Yuu<WHITE>- the legendary <PURPLE>GAME BOY<WHITE>, will journey into the <RED>DARK WORLD<WHITE> of the <RED>video game industry<WHITE> and discover the <RED>TRUTH<WHITE> about the EVIL companies that make the games he loves.<.>"


							"Instead of repetitive RPG battles, there is focus on exploring, problem solving, and puzzles...<.>"
							"In order for <PURPLE>Yuu<WHITE> to DISCOVER and COLLECT <PAUSE>"
							"<YELLOW><HUGE>PLAYABLE GAMES<WHITE><NORMAL><PAUSE><NEXTLINE>"
							"for his <GRAY>Gantendo <GRAY>BS<WHITE> handheld gaming console!<.>"

							"<GRAY>BS<WHITE> standing for <GRAY>bottom screen<WHITE>, of course. (But it's also rumored to have dual meanings...)<.>"

							"These games are not \"mini-games\" - each game is comparable to a <GREEN>full, retail game!<WHITE><.>"
							"<GREEN>\"bob's game\"<WHITE> is many games in one!<.>"
							//"There's even a platformer the size of a well known indie game."
							//"Because \"bob's game\" is 64 megabytes. That game is 1."

							"<PURPLE>Yuu<WHITE> will COMPETE in <RED>GAME CHALLENGES<WHITE> and <RED>MULTIPLAYER BATTLES<WHITE> to EARN THE RESPECT of his peers and progress the story.<.>"

							"<PURPLE>Yuu<WHITE> will travel far and wide in the <GREEN>ULTIMATE EPIC QUEST<WHITE> to acquire the <RED>HOLY GRAIL OF VIDEO GAMES<WHITE>-<.>"

							"<GREEN><HUGE>THE GREATEST <NEXTLINE>GAME EVER MADE<NORMAL><WHITE><.>"
							"A game <RED>SO GOOD<WHITE>, it had been <RED>BANNED<WHITE> from the VIDEO GAME INDUSTRY-<.>"

							"<HUGE>the LEGENDARY <NEXTLINE><GREEN>\"bob's game\"<WHITE><NORMAL><.>"
							"A <NEXTLINE><RED>multiplayer <PAUSE><NEXTLINE>competitive <PAUSE><NEXTLINE>tournament<WHITE><PAUSE><NEXTLINE>"
							"<GREEN>PUZZLE GAME<WHITE><.>"
							"A brand new idea- <RED>more addictive than TETRIS!<WHITE><NORMAL><.>"

							"Using the <GRAY>Gantendo <GRAY>BS<WHITE> internet connection,<PAUSE><NEXTLINE>"
							"<PURPLE>Yuu<WHITE> will COMPETE in a <RED>VIRTUAL<WHITE> and <RED>REAL-LIFE<WHITE> <GREEN>INTERDIMENSIONAL WORLD-WIDE CHAMPIONSHIP<WHITE><PAUSE><NEXTLINE>"
							"against <GREEN>THE GREATEST GAME DEVELOPER IN HISTORY-<WHITE><PAUSE><NEXTLINE>"
							"<HUGE>the LEGENDARY <GREEN>\"bob\"<WHITE><NORMAL><.>"

							"And <PURPLE>Yuu<WHITE> might just discover that <GREEN>\"bob\"<WHITE> was no villain all along.<.>"

							//"He's just a crazy genius."

							*/




/*
							"\"bob's game\""

							The game is real, both inside and out.
							The villainous developer is real, both inside and out.
							The tournament is real, both inside and out.


							It should be obvious by now that
							The bobsgame.com website is an elaborate viral ad
							creating a real-life parallel to the in-game events
							while poking fun at the actual state of the game industry
							making "bob's game" truly the first interdimensional game

							the clues were there all along, if you looked closely- and if you were willing to see it.
							and there are still more clues, hidden in the wall of insanity that is bobsgame.com

							the call for publishers
							the underground fortress
							the interdimensional tournament
							the protest
							the meeting
							the rampage - fake, of course
							the transformation
							the nintendo world store - fake of course.




							//remember, i was locked in a room for five years.
							//i told you, it's actually really cool.
							//so what is the game and what is real?




							this has been planned from day one.

							because in 10 days, on day 100

							at the game developers conference 2012

							the REAL TRUTH

							will be revealed.

*/









						/*	"bob's game" still doesn't have a publisher...
							but not because of a conspiracy.. or is it?

							it's because "bob's game" is too radical of an idea.
							once the publishers found out what kind it was, they wouldn't dare take the risk

							the only solution was to self-publish
							so i applied for licensing, in order to purchase the sdk.

							but nintendo has spoken.
							i do work from a commercial office.
							i am a registered company, with a tax id.





							but this viral advertisement is more than just an advertisement

							in acting out the game events
							i have actually shown you the truth

							you could create a masterpiece
							one of the best games in years

							and take it to a company
							that says they're all about great games

							and they won't care.
							no matter what you do.*/




				);



				/*


















				*/




				/*

						"<1>Well, where are your figures?<.>"
						"Did you bring any data?<.>"

						"<0>What? Data for what?<.>"

						"<1>Look, don't waste my time here.<.>"
						"Every game idea has to go through market testing before it's even considered for development.<.>"
						"It's standard practice. You have to look at what sells.<.>"

						"<0>Well it'll obviously sell.<.>"
						"You don't even have to worry about development, it's done!<.>"
						"Here, play it! You'll know right away.<.>"

						"<1>That's.. not how it works.<.>"
						"You're either going to have to put it through market testing, or you're going to have to have data for similar games on the market.<.>"

						"<0>Well, my game is sort of a new idea, so how does market testing work? I'm not really familiar..<.>"

						"<1>Right.<.>"
						"You're obviously new to this, so I'll tell you how it works.<.>"
						"New ideas are risky. Companies can't afford to take risks all the time.<.>"
						"Sure, there are some improvements here and there, but this is business.<.>"
						"We can't just try something without having any data on it.<.>"
						"We need to have numbers.<.>"
						"We need to know how many copies it'll sell to what age groups.<.>"

						"<0>Well alright, but the game is great! It's obvious!<.>"
						"It'll do great, so there's no risk!<.>"
						"Any gamer should be able to tell right away.<.>"
						"You won't even need to test it! Just look! Play it!<.>"

						"<1>Look, kid. I wouldn't know the difference.<.>"
						"They're all the same to me.<.>"

						"<0>What? Seriously?<.>"

						"<1>How would I know? They're toys. You really think we play those things?<.>"

						"<0>Well, actually, I sort of did.<.>"

						"<1>What, do you think doll company executives play with dolls all day?<.>"

						"<0>I never really thought about it that way...<.>"
						"Hmm.. So then, you can put it through the market testing! They'll love it!<.>"
						"You'll see! It's totally fresh! It'll blow them right out of the water!<.>"
						"It's one of the best ideas in years! They've never seen anything like it!<.>"
						"It's fun! That's all that matters, right?<.>"

						"<1>Hold on. Slow down for a second.<.>"
						"We get this all the time.<.>"
						"We see hundreds of these \"great ideas\" every single day, and yet very few become products.<.>"
						"Why do you think that is?<.>"

						"<0>Well, ok... Why are there so many terrible games then? Where do all the good ideas go?<.>"
						"Seriously, you have to know that most of what's out there is awful!<.>"

						"<1>You're missing the point. Why don't you think about this for a second, from a business perspective? It's simple.<.>"
						"Since we control the retail shelf space, we can ensure that our games are always the highest quality available- so they will continue selling the most.<.>"
						"The games you call \"awful\" are actually targeted towards a specific audience, and those games are replaced regularly to keep the market fresh.<.>"
						"They aren't intended to compete with the higher quality titles. That's why there are several different price points.<.>"

						"<0>So, you're saying there's actually a limit on high quality games? That doesn't make sense!<.>"

						"<1>Of course it does. When new games come out, people stop buying the older ones.<.>"
						"Development is expensive, and there's no reason to release new games while the games that are available are still selling.<.>"
						"Allowing competitive titles into the market would increase our own development costs. We control the market, so there's no reason to do so.<.>"
						"Our partners are limited to a certain number of releases for the higher price points for this reason, which allows our titles the highest priority.<.>"
						"A company of our size could put out a AAA game every day if we wanted. It's simply not profitable.<.>"

						"<0>I guess... Wow. I really never realized that. That makes a lot of sense.<.>"
						"<0>So, you're not even going to look at my idea?<.>"

						"<1>Not unless you have data.<.>"

						"<0>Ok then.. So... Wait. What about all those things you guys say?<.>"
						"You're all about fun, and games are all that matter.<.>"
						"Why do you say it if you don't really care?<.>"

						"<1>Don't forget, it's just a business like any other.<.>"
						"Like any business, we just say what customers want to hear.<.>"
						//"If people knew how it really worked, they'd demand more.<.>"
						"They're just slogans, marketing phrases that get kids like you excited.<.>"

						"It worked, didn't it?<.>"

						"<0>I don't believe this.<.>"
						"I believed all that stuff!<.>"

						"<1>Some people will believe anything.<.>"
						"You probably believed in Santa too. Guess what- he's not real. Sorry.<.>"

						"<0>Man, I grew up thinking you guys were these super developers living the dream.<.>"
						"That's why I became a developer in the first place.<.>"
						"You're saying that's not true?<.>"

						"<1>Oh come on. Time to wake up, kid.<.>"
						"You really think we care about the crap we sell? They're just toys, plain and simple, nothing more.<.>"

						"<0>I don't think games are toys. Gamers take games pretty seriously, you know.<.>"

						"<1>They're toys. Your \"gamers\" are just freaks that won't grow up. They're embarrassing, honestly.<.>"
						"Full grown men locking themselves in rooms full of stuffed animals.<.>"
						"You can't imagine how hard it is not to laugh sometimes.<.>"

						"<0>Hey, I'm a gamer.<.>"

						"<1>Yeah, I see that. You're a mess. Cut your hair and get some decent clothes.<.>"
						"Let me give you some advice. You won't make it anywhere in business if you care about what you make.<.>"
						"You might be the best chef in the world, but most people won't know the difference if we serve them dog food.<.>"
						"You stay in the kitchen, and we handle the business. You have to know your place.<.>"

						"<0>I can't believe you're telling me this.<.>"
						"Don't you realize everyone takes all of that seriously?<.>"
						"All those people believe in you, you know.<.>"

						"<1>That's right. They always will, too. They're naive, like you.<.>"
						"We string em' along for as long as we can, then they grow up and learn like the rest of us.<.>"
						"Of course, some of them just stay children forever. Is that what you want to be?<.>"

						"<0>I... I... I don't... I guess not...<.>"

						"<1>I didn't think so.<.>"

						"<0>Hold on a second!<.>"
						"I don't believe this!<.>"
						"Why are you even working here in the first place?!<.>"
						"Don't you realize how much people care about games?<.>"
						"It's digital art, a virtual experience, immersive human expression! It means something!<.>"
						"For some kids it's all they have! It's all they look forward to!<.>"
						"Didn't you ever care about games?!<.>"

						"<1>Are you serious? Care about games?<.>"
						"No, thank god. I went to business school and played basketball.<.>"
						"Sure, I've played Pong a couple times, but I'm not some pale nerd reject obsessed with toys.<.>"
						"I will never understand you freaks.<.>"
						"So why don't you go ahead and use your game as a resume, and maybe you can get a job working for one of the big developers.<.>"
						"Who knows? You might even get to see your name on one of those \"awful games\" someday. *chuckle*<.>"

						"<0>A resume?! No way! This game is great! People are gonna love it! It'll sell millions!<.>"
						"I'm not going to just throw away an idea like this!<.>"
						"Do you even know how hard it is to make a game?!<.>"

						"<1>Oh come on. Can't be that hard. They're a dime a dozen.<.>"

						"<0>It takes thousands of hours! It's painstaking!<.>"

						"<1>You keyboard jockeys sit at computers all day anyway. What's the difference?<.>"

						"<0>What?! Have you ever made anything in your life?<.>"
						"Do you know what it's like to try your best? I bet you've never worked hard on anything!<.>"

						"<1>That's right. I don't need to. Why don't you take a look at what side of the table you're on? Maybe you'll figure it out.<.>"

						"<0>I don't care what words you tack onto your name, that doesn't mean a thing!<.>"
						"Are you even good at anything?! You're just using talented people because you don't have any yourself.<.>"
						"That's right, isn't it?<.>"

						"<1>Who the hell do you think you're talking to?!<.>"

						"<0>You know what?!<.>"
						"I'll tell you what I really think. You know what I see?<.>"
						"You're just a leech!<.>"
						"You aren't trying your best! You aren't trying at all!<.>"
						"You're scamming people. You're lying to kids.<.>"
						"You're just making excuses and justifying yourself, saying anything else is naive or unprofessional.<.>"
						"That's not professional. You don't even have a profession! That's dressing up in a suit and being a dick!<.>"
						"You're taking advantage of your fans. You're ripping off children.<.>"
						//"You really think you're doing the right thing?<.>"
						"Is that what YOU wanted to be? Are you proud of yourself?<.>"
						"This is the game industry?! You guys were my heroes!<.>"
						"I came here expecting talent, dedicated people.<.>"
						"People would give anything to work here, don't you know that?<.>"
						"Do you have any idea how angry they'd be?!<.>"

						"<1>*chuckle*<.>"
						"And what exactly are you going to do about it?<.>"
						"Do you have any idea who you're talking to?<.>"
						"I've got connections that you can't possibly imagine.<.>"
						"I give you MY time, and you want to disrespect me?<.>"
						"Look, kid. I'll tell you right now. I've already made my decision.<.>"
						"I gave you a chance, and you just blew it. You just don't know when to quit.<.>"
						"It's just too bad. You could've made it if you'd just kept your mouth shut.<.>"

						"<0>Alright, I get it. It's just the way things are, right?<.>"
						"Sorry for taking your time.<.>"
						"Man, I can't believe I was so wrong about you.<.>"

						"<1>You'd better believe it. That's the way things are.<.>"
						"You guys just think you're so smart, don't you?<.>"
						"There's a reason we stick you freaks in cubes. Welcome to the real world.<.>"

						"<0>Freaks? Without US you wouldn't have anything to sell!<.>"

						"<1>Yeah, right. Don't kid yourself.<.>"
						"If you don't like it, we hire someone else. Why don't you take a look around?<.>"
						"This place is full of bright guys that'll take your place in a second.<.>"
						"We don't need you. You need us, and we know it. That's just the way it is.<.>"

						"<0>Yeah, fine.<.>"
						"I see how it is.<.>"
						"I picked the wrong company.<.>"
						"Obviously I expected way too much from you guys.<.>"
						"I'll keep trying, no problem.<.>"
						"Someone out there will understand it.<.>"
						"Not everyone is like you.<.>"
						"My game will get released.<.>"

						"<1>You know what? Sadly, I'm afraid your game will never be released.<.>"
						"The publishers go through us. The licensing goes through us.<.>"
						"We control the whole process, genius. Go ahead, keep trying.<.>"
						"In fact, I invite you to apply. See what happens.<.>"
						"I suggest that you figure out what you're going to do.<.>"
						"Your career in gaming is OVER, and so is this meeting.<.>"

				);*/

		}


}

void bobsgame_MISCMeetingRoom_Map_Stop_Function()
{
	NPC_delete_all_npcs();
}
void bobsgame_MISCMeetingRoom_Map_VBL_Function()
{

}

void bobsgame_MISCMeetingRoom_Map_HBL_Function()
{

}

