public interface Protocol{
	int NUMBER=1;
	int RESULT=2;
	int QUIT=3;
	int PORT = 10000;
}

/*
Clinet side:					Server side:
-----------------------------------------------------
NUMBER n 		n:int 			RESULT n
QUIT							close the connection
------------------------------------------------------
*/
