import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

public class Quiz3_W02 extends Application {
   private VBox root;
   private TextField n1, n2,result;

   
   @Override
   public void start(Stage primaryStage) {
      root = new VBox(5);  
      root.setAlignment(Pos.CENTER);  
      n1 = new TextField("1.0");  
      n2 = new TextField("1.0");  
      n2.setOnAction(new MyEeventHandler());
      result = new TextField("1.0");  
      root.getChildren().add(n1); 
      root.getChildren().add(n2); 
      createButton();
      root.getChildren().add(result);
      Scene scene = new Scene(root); 
      primaryStage.setTitle("Quiz");
      primaryStage.setScene(scene);
      primaryStage.show();
   }
  
   private void createButton(){
      Button divideButton = new Button("Divide");
      root.getChildren().add(divideButton);
      divideButton.setOnAction(new MyEeventHandler());

   }
  
   private class MyEeventHandler implements EventHandler<ActionEvent> {
      @Override
      public void handle(ActionEvent event) {
         double first = Double.parseDouble(n1.getText());
         double second = Double.parseDouble(n2.getText());
         String resultStr = first/second+""; 
         if(second==0)
            result.setText("cannot divide by zero");
         else 
            result.setText(resultStr);
      }
   }

   public static void main(String[] args) {
      Application.launch(args);
   }
}
