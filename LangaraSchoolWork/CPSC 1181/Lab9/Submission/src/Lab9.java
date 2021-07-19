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
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.time.DateTimeException;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.Period;
import java.time.temporal.ChronoUnit;

public class Lab9 extends Application{

        private TextField startDate;
        private TextField endDate;
        private Button startButton;
        private VBox root;
        private DateVerifier verifier;

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
                ButtonEventHandler buttonE = new ButtonEventHandler();
                startButton.setOnAction(buttonE);

        }

        private class ButtonEventHandler implements EventHandler<ActionEvent> {

                private ButtonEventHandler(){

                }

                public void handle(ActionEvent e){
                        String textField1 = startDate.getText();
                        String textField2 = endDate.getText();
                        String displayString = "";
                        String outPutString = "";

                        try {
                                verifier = new DateVerifier();
                                LocalDate date1 = verifier.verify(textField1, "Start Date : ");
                                LocalDate date2 = verifier.verify(textField2, "End Date : ");
                                Period datesBetween = Period.between(date1, date2);
                                long daysBetween = ChronoUnit.DAYS.between(date1, date2);
                                outPutString = datesBetween.getDays() + " days \n" + datesBetween.getMonths() + " months \n" + datesBetween.getYears() + " years \n" + daysBetween + " total days";
                                popUpWindow(outPutString);
                        }catch (DateTimeException o){
                                displayString = o.getMessage();
                                popUpWindow(displayString);
                        }catch (CPSC1181Exception p){
                                displayString = p.getMessage();
                                popUpWindow(displayString);
                        }
                }


        }

        private void popUpWindow(String input){
                Stage stage = new Stage();
                stage.initModality(Modality.APPLICATION_MODAL);
                VBox popUpBox = new VBox(10);
                Text inputText = new Text(input);
                popUpBox.getChildren().add(inputText);
                Scene scene = new Scene(popUpBox,400,250);
                stage.setScene(scene);
                stage.show();
        }


}
