import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.time.LocalDate;
import java.time.LocalDateTime;

public class Lab9 extends Application{

        private TextField startDate;
        private TextField endDate;
        private Button startButton;
        private VBox root;

        public static void main(String[]args){
        launch(args);
        }

        @Override
        public void start(Stage primaryStage){

                root = new VBox(4);
                Scene scene = new Scene(root);
                primaryStage.setTitle("Lab9");
                createFirstRow();
                createSecondRow();
                createButton();
                primaryStage.setScene(scene);
                primaryStage.show();

        }

        private void createFirstRow(){

                Label label = new Label("Start Date: ");
                startDate = new TextField("1/1/2000");
                HBox firstBox = new HBox(5,label,startDate);
                firstBox.setPadding(new Insets(10,10,10,10));
                root.getChildren().add(firstBox);
        }

        private void createSecondRow(){

                Label label = new Label("End Date: ");
                String dateToday = LocalDateTime.now().getDayOfMonth() + "/" + LocalDateTime.now().getMonthValue() + "/" + LocalDateTime.now().getYear();
                endDate = new TextField(dateToday);
                HBox secondBox = new HBox(5,label,endDate);
                secondBox.setPadding(new Insets(10,10,10,10));
                root.getChildren().add(secondBox);

        }

        private void createButton(){

                startButton = new Button("Count");
                root.setAlignment(Pos.CENTER);
                root.getChildren().add(startButton);
                VBox box = root;
                VBox.setMargin(startButton,new Insets(10,10,10,10));

        }

        private class ButtonEventHandler implements EventHandler<ActionEvent> {

                private ButtonEventHandler(){

                }

                public void handle(ActionEvent e){

                }


        }


}
