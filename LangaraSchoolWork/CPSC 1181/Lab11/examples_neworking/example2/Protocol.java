public interface Protocol{
	int DATA=1;
	int END=2;
	int PORT=10000;
}


/*
Clinet side:	 				  Server side:
-------------------------------------------------------
DATA message   message: String
END								  close the connection
-------------------------------------------------------

*/
