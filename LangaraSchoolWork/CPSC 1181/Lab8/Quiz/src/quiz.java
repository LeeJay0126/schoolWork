import javafx.application.Application;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.event.ActionEvent;

import javafx.scene.control.Button;


public class quiz extends Application {

    VBox root;
    TextField num1;
    TextField num2;
    TextField num3;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {

        root = new VBox();
        num1 = new TextField("1.0");
        num2 = new TextField("1.0");
        num3 = new TextField("1.0");
        Button divide = new Button("Divide");

        DivideButton buttonHandler = new DivideButton();
        divide.setOnAction(buttonHandler);

        num1.setPrefWidth(100);
        num2.setPrefWidth(100);
        num3.setPrefWidth(100);

        root.setAlignment(Pos.CENTER);
        root.setPadding(new Insets(0,0,5,0));

        root.getChildren().addAll(num1,num2,divide,num3);

        Scene scene = new Scene(root);
        primaryStage.setTitle("Quiz");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private class DivideButton implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {

            double num1Value = Double.parseDouble(num1.getText());
            double num2Value = Double.parseDouble(num2.getText());

            if(num2Value == 0){
                System.out.println("Cannot divide by zero");
            }else{
                Double result = num1Value/num2Value;
                String output = "" + result;
                num3.setText(output);
            }

        }

    }

}


