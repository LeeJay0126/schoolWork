// Five Stones Game
import java.util.Scanner;

public class FiveStones
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		
		final int SIZE = 9;
		char[][] grid = new char[SIZE][SIZE];
		
		displayGrid(grid);
		
		int count = 0;
		int xOrO= 0;
		while(count < 81){
			
			System.out.print("Where do you want to place your stone? (Enter row number): ");
			int row = input.nextInt();
			Sytem.out.print("Where do you want to place your stone? (Enter column number):");
			int column = input.nextInt();
			
			if(xOrO % 2 = 0){
				grid[row][column] = "O";
			}else{
				grid[row][column] = "X";
			}
			
			int rowCount = 0;
			for(int k = 0; k < column; k++){
				rowCount = 0;
				for(int i = 0; i < row; i++){
					if(row[k][i] == "O"){
						rowCount++;
					}
				}
			}
		}
	}

	// Display the grid
	public static void displayGrid(char[][] grid)
	{
		// Display the col numbers
		System.out.print("\n   ");
		for(int i = 0; i < grid[0].length; i++)
			System.out.print(i + "  ");
		System.out.println();
		
		
		for(int i = 0; i < grid.length; i++)
		{
			System.out.println("  ----------------------------");
			
			// Display the row number
			System.out.print(i + " ");
			
			// Display the squares
			for(int j = 0; j < grid[i].length; j++)
			{
				if(grid[i][j] != 'x' && grid[i][j] != 'o')
					System.out.print("|  ");
				else 
					System.out.print("| " + grid[i][j]);
			}
			System.out.println("|");
		}
		
		System.out.println("  ----------------------------");
	}
	
}