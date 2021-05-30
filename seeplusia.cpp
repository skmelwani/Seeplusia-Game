#include "seeplusia.hpp"
#include "mover.hpp"

int applesLeft = 30, nCrystalsFound = 0;
string gameState  = "Running";
string cur_place = "Enchanted Forest";
bool marsh = true;
bool hill = true;
bool waterfall = true; 



void makeMove(string direction)
{
	if (direction == "East" && gameState == "Running") //When Right Arrow is pressed
	{ 
		if (cur_place == "Enchanted Forest") // move from enchanted to swamps
		{
			if (applesLeft > 1)
			{
				cout<<"enchanted to swamps"<<endl;
				moveEast(); 
				applesLeft-=2;
				cur_place = "Swamps of Despair";
			}
		}
		else if (cur_place == "Bridge of Death") //from bridge to enchanted
		{
			if (applesLeft > 0)
			{
			cout<<"bridge to enchanted"<<endl;
			moveEast(); 
			applesLeft--;
			cur_place = "Enchanted Forest";	
			}			
		}
		else if (cur_place == "Marsh of Undead") //from Marsh to Sands
		{
			if (applesLeft > 0)
			{
				cout<<"Marsh to Sands"<<endl;
				moveEast(); 
				applesLeft--;
				cur_place = "Sands of Quick";
				gameState = "Lost";    // Lost at sands
			}
		}
		else 
		{
			applesLeft--;   //invalid move
		}
	}

	else if (direction == "West" && gameState == "Running")  //When Left Arrow is pressed
	{ 
		if (cur_place == "Swamps of Despair")   // From Swamps to enchanted
		{
			if (applesLeft > 1)										//Won't move if dont have enough apples
			{
				cout<<"Swamps to enchanted"<<endl;
				moveWest();  	
				applesLeft-=2;
				cur_place = "Enchanted Forest";
			}
		}
		else if (cur_place == "Enchanted Forest")  //from enchanted to bridge
		{
			if (applesLeft > 0)
			{
				cout<<"enchanted to bridge"<<endl;
				moveWest();  	
				applesLeft--;
				cur_place = "Bridge of Death";
			}
		}
		else if (cur_place == "Bridge of Death")
		{
			if (nCrystalsFound == 3 && applesLeft > 4)     //go wizard's only if diamond =3 and apples are 5
			{
				cout<<"Bridge of Death to Wizard's Castle"<<endl;
				moveWest();  	
				applesLeft-=5;
				cur_place = "Wizard's Castle";
				gameState = "Won";
			}
			else if (nCrystalsFound != 3 || applesLeft < 5)   //if no diamods or enough apples
			{
				cout<<"Not enough crystal/apples"<<endl;
				gameState = "Lost";
			}

		}
		else 
		{
			applesLeft--;   //invalid move
		}
	}
	else if (direction == "North" && gameState == "Running") //When Up Arrow is pressed
	{ 
		if (cur_place == "Enchanted Forest")   //from encahnted to Marsh
		{
			if (applesLeft > 0)
			{
				cout<<"Enchanted Forest to Marsh of Undead"<<endl;
				moveNorth(); 
				applesLeft--;
				cur_place = "Marsh of Undead";
			
				if (marsh == true)			//collect diamond
				{
					nCrystalsFound++;
					marsh = false;
				}
			}

		}
		else if (cur_place == "Swamps of Despair")  //from swamps to sands
		{
			if (applesLeft > 1)
			{
				cout<<"swamps of Despaai r to Sand of Quick"<<endl;
				moveNorth(); 
				applesLeft-=2;
				cur_place = "Sands of Quick";
				gameState = "Lost";		//die at sands
			}

		}
		else if (cur_place == "Vampire Cove")
		{
			if (applesLeft > 2)
			{
				cout<<"Vampire Cove to Enchanted forest"<<endl;
				moveNorth(); 
				applesLeft-=3;
				cur_place = "Enchanted Forest";
			}
		}

		else if (cur_place == "Werewolf Hill")
		{
			
			if (applesLeft > 2)
			{
				cout<<"Werewolf to Vampire Cove"<<endl;
				moveNorth(); 
				applesLeft-=3;
				cur_place = "Vampire Cove";
			}
		}
		else if (cur_place == "Elven Waterfall")
		{
			if (applesLeft > 0)
			{
				cout<<"Elven Waterfall to Swamps of Despair"<<endl;
				moveNorth(); 
				applesLeft--;
				cur_place = "Swamps of Despair";
			}
		}
		else 
		{
			applesLeft--;    //invalid move
		}

	}
	else if (direction == "South" && gameState == "Running")		 //When Up Arrow is pressed
	{
		if (cur_place == "Enchanted Forest")
		{
			if (applesLeft > 2)
			{	
				cout<<"Enchanted Forest to Vampire Cove"<<endl;
				moveSouth(); 
				applesLeft-=3;
				cur_place = "Vampire Cove";
			}
		}
		else if (cur_place == "Vampire Cove")
		{
			if (applesLeft > 2)
			{
				cout<<"Vampire cove to Werewolf hill"<<endl;
				moveSouth();
				applesLeft-=3;
				cur_place = "Werewolf Hill";
				if (hill == true)   //collection crystal
			
				{
					nCrystalsFound++;
					hill = false;
				}
			}
									
		}
		else if (cur_place == "Swamps of Despair")
		{
			if (applesLeft > 0)
			{
				cout<<"Swamps of Despair to Elven Waterfall"<<endl;
				moveSouth();
				applesLeft--;
				cur_place = "Elven Waterfall";
				if (waterfall == true)   //collectio=ng crystal
				{
					nCrystalsFound++;
					waterfall = false;
				
				}
			}
		}
		else if (cur_place == "Marsh of Undead")
		{
			if (applesLeft > 0)
			{
				cout<<"Marsh of Undead to Enchanted Forest"<<endl;
				moveSouth(); 
				applesLeft--;
				cur_place = "Enchanted Forest";
			}
		}
		else 
		{
			applesLeft--;    //invalid move
		}

	}
	if (applesLeft < 1 && cur_place != "Wizard's Castle")    //lost if apples finished befroe winning
	{
		gameState ="Lost";
	}

}
