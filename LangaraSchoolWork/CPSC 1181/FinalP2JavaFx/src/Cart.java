import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Cart extends Application {

    private String[] items = {"Potato", "Egg", "Chicken", "Milk", "Bread"};
    private VBox centerPane;
    private TextArea output;
    private CheckBox Potato;
    private CheckBox Egg;
    private CheckBox Chicken;
    private CheckBox Milk;
    private CheckBox Bread;
    private Button Add;



    @Override
    public void start(Stage primaryStage) {
        BorderPane root = new BorderPane();
        Scene scene = new Scene(root,600,500);

        centerPane = new VBox(20);
        centerPane.setPadding(new Insets(20, 20,20, 20));
        centerPane.setAlignment(Pos.CENTER);

        Potato = new CheckBox("Potato");
        Egg = new CheckBox("Egg");
        Chicken = new CheckBox("Chicken");
        Milk = new CheckBox("Milk");
        Bread = new CheckBox("Bread");

        HBox checkVBox = new HBox(10);
        checkVBox.getChildren().addAll(Potato,Egg,Chicken,Milk,Bread);
        checkVBox.setAlignment(Pos.CENTER);

        Add = new Button("Add");
        CheckBoxListener addButtonEvent = new CheckBoxListener();
        Add.setOnAction(addButtonEvent);

        VBox centerPaneOptions = new VBox(10);
        centerPaneOptions.getChildren().addAll(checkVBox,Add);
        centerPaneOptions.setAlignment(Pos.CENTER);

        centerPane.getChildren().addAll(centerPaneOptions);

        root.setCenter(centerPane);



        output = new TextArea();
        output.setEditable(false);
        HBox outputpane = new HBox(10, output);
        outputpane.setAlignment(Pos.CENTER);
        outputpane.setPadding(new Insets(25, 25, 25, 25));
        centerPane.getChildren().add(output);



        root.setBottom(outputpane);
        primaryStage.setTitle("CART");
        primaryStage.setScene(scene);
        primaryStage.show();
    }



    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

    private class CheckBoxListener implements EventHandler<ActionEvent>{

        @Override
        public void handle(ActionEvent event) {
            String resultString = "[";
            int count = 0;

            output.setText("");

            if(Potato.isSelected()){
                if(count != 0){
                    resultString += ", ";
                }
                resultString += items[0];
                count ++;
            }

            if(Egg.isSelected()){
                if(count != 0){
                    resultString += ", ";
                }
                resultString += items[1];
                count ++;
            }

            if(Chicken.isSelected()){
                if(count != 0){
                    resultString += ", ";
                }
                resultString += items[2];
                count ++;
            }

            if(Milk.isSelected()){
                if(count != 0){
                    resultString += ", ";
                }
                resultString += items[3];
                count ++;
            }

            if(Bread.isSelected()){
                if(count != 0){
                    resultString += ", ";
                }
                resultString += items[4];
                count ++;
            }

            resultString += "]";

            if(count == 0){
                output.setText("Cart is Empty");
            }else{
                output.setText(resultString + "\n" + "Number of items in cart:" + count);
            }

        }
    }


}


