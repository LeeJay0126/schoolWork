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

/**
 * Referred from Lab9.zip from lab notes
 */
public class Lab9 extends Application{

        private TextField startDate;
        private TextField endDate;
        private Button startButton;
        private VBox root;
        private DateVerifier verifier;

        public static void main(String[]args){
        launch(args);
        }

        /**
         * Initializing basic features/ visuals We need for javafx
         * including setting a title, setting a root, setting a scene
         * and showing primary stage.
         * @param primaryStage
         */
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

        /**
         * Creating first row (first text box and it's label)
         * and adding it to the root.
         */
        private void createFirstRow(){

                Label label = new Label("Start Date: ");
                startDate = new TextField("1/1/2000");
                HBox firstBox = new HBox(5,label,startDate);
                firstBox.setPadding(new Insets(10,10,10,10));
                root.getChildren().add(firstBox);
        }

        /**
         * Second row (second text box and it's label)
         * and adding it to the root
         */
        private void createSecondRow(){

                Label label = new Label("End Date: ");
                String dateToday = LocalDateTime.now().getDayOfMonth() + "/" + LocalDateTime.now().getMonthValue() + "/" + LocalDateTime.now().getYear();
                endDate = new TextField(dateToday);
                HBox secondBox = new HBox(5,label,endDate);
                secondBox.setPadding(new Insets(10,10,10,10));
                root.getChildren().add(secondBox);

        }

        /**
         * Creates button that handles event.
         * create/add/ and links event handler to the button
         */
        private void createButton(){

                startButton = new Button("Count");
                root.setAlignment(Pos.CENTER);
                root.getChildren().add(startButton);
                VBox box = root;
                VBox.setMargin(startButton,new Insets(10,10,10,10));
                ButtonEventHandler buttonE = new ButtonEventHandler();
                startButton.setOnAction(buttonE);

        }

        /**
         *event handler method for the button
         */
        private class ButtonEventHandler implements EventHandler<ActionEvent> {
                /**
                 * Get the string value from the text boxes.
                 * run it through check method in DateVerifier class and get return value of LocalDate.
                 * If failed, throws an exception and displayin the message in a popup window.
                 * If succeeded, store the result in to a string and display in a popup window.
                 * @param e
                 */
                public void handle(ActionEvent e){
                        String textField1 = startDate.getText();
                        String textField2 = endDate.getText();
                        String displayString = "";
                        String outPutString = "";
                        try {
                                verifier = new DateVerifier();
                                LocalDate date1 = verifier.check(textField1, 1);
                                LocalDate date2 = verifier.check(textField2, 2);
                                Period datesBetween = Period.between(date1, date2);
                                System.out.println(datesBetween.getDays() + "days" + datesBetween.getYears() + datesBetween.getMonths());
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

        /**
         * takes in a string as an input
         * and displays it in a popup window.
         * @param input
         */
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
