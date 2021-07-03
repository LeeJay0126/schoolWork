import javafx.application.Application;
import javafx.stage.Stage;

import javafx.scene.Scene;
import javafx.scene.text.Text;
import javafx.scene.layout.GridPane;
import javafx.scene.control.Button;
import javafx.geometry.HPos;
import  javafx.geometry.Pos;

public class GridPaneSpanFX extends Application {

	@Override
	public void start(Stage primaryStage) {
		
        primaryStage.setTitle("GridPane");

        Button button1 = new Button("Button 1");
        Button button2 = new Button("Button 2");
        Button button3 = new Button("Button 3");
        Button button4 = new Button("Button 4");
        Button button5 = new Button("Button 5");
        Button button6 = new Button("Button 6");
        Button button7 = new Button("Button 7");
        Button button8 = new Button("Button 8");
     

        GridPane gridPane = new GridPane();

     
        gridPane.add(button1, 0, 0,2,2); // span two col and rows
        GridPane.setHalignment(button1, HPos.CENTER); // center aligned
        gridPane.add(button2, 2, 0);
        gridPane.add(button3, 2, 1);
      
        gridPane.add(button4, 0, 2);
        gridPane.add(button5, 1, 2); 
        gridPane.add(button6, 2, 2); 
   
       
        Scene scene = new Scene(gridPane);
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        Application.launch(args);
    }

}