package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.*;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;


public class Main extends Application {

    private BorderPane root;
    private RadioButton degree0;
    private RadioButton degree90;
    private RadioButton degree180;
    private RadioButton degree270;
    private CheckBox rain;
    private CheckBox smile;
    private ToggleGroup degrees;
    private Button textButton;
    private Pane Trees;
    private Circle sunBase;
    private Circle eye1;
    private Circle eye2;
    private Arc mouth;
    private Group smiley;

    @Override
    public void start(Stage primaryStage) throws Exception{

        root = new BorderPane();

        Text background = new Text("Background");
        background.setFont(Font.font("Arial",14));
        rain = new CheckBox("rainbow");
        smile = new CheckBox("smile");

        HBox rainOrSmile = new HBox(10);
        rainOrSmile.getChildren().addAll(rain,smile);

        CheckBoxesListener smileListener = new CheckBoxesListener();
        smile.setOnAction(smileListener);


        VBox firstVbox = new VBox(10,background,rainOrSmile);
        firstVbox.setAlignment(Pos.CENTER);
        firstVbox.setPadding(new Insets(10,5,10,5));

        degree0 = new RadioButton("0 Degree");
        degree90 = new RadioButton("90 Degree");
        degree180 = new RadioButton("180 Degree");
        degree270 = new RadioButton("270 Degree");

        degrees = new ToggleGroup();

        degree0.setToggleGroup(degrees);
        degree90.setToggleGroup(degrees);
        degree180.setToggleGroup(degrees);
        degree270.setToggleGroup(degrees);

        VBox radioButtons = new VBox(10,degree0,degree90,degree180,degree270);
        radioButtons.setPadding(new Insets(20,5,20,5));

        VBox secondVbox = new VBox(firstVbox,radioButtons);

        Text caption = new Text("Caption");
        caption.setFont(Font.font("Arial",14));
        TextField textField = new TextField("");
        textField.setPrefWidth(100);
        textButton = new Button("Change Text");

        VBox textVbox = new VBox(15,caption,textField,textButton);
        textVbox.setPadding(new Insets(20,5,0,5));
        textVbox.setAlignment(Pos.CENTER);

        VBox thirdVbox = new VBox(secondVbox, textVbox);

        Trees = new Pane();
        Tree tree = new Tree();

        sunBase = new Circle(330, 60, 30);
        eye1 = new Circle(345, 45, 5);
        eye2 = new Circle(315, 45, 5);
        mouth = new Arc(330, 75, 20, 20, 0, 100);

        mouth.setType(ArcType.CHORD);

        sunBase.setFill(Color.TRANSPARENT);
        eye1.setFill(Color.TRANSPARENT);
        eye2.setFill(Color.TRANSPARENT);
        mouth.setFill(Color.TRANSPARENT);

        smiley = new Group(sunBase,eye1,eye2,mouth);

        Trees.getChildren().add(smiley);

        HBox finalBox = new HBox(thirdVbox,Trees);

        Scene scene = new Scene(finalBox);

        primaryStage.setTitle("CPSC1181 Lab 7");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();


    }

    private class CheckBoxesListener implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {

            Color sunColor = Color.TRANSPARENT;
            Color eyeColor = Color.TRANSPARENT;
            Color mouthColor = Color.TRANSPARENT;

            if(smile.isSelected()) {

                sunColor = Color.YELLOW;
                eyeColor = Color.BLACK;
                mouthColor = Color.BLACK;

            }

            sunBase.setFill(sunColor);
            eye1.setFill(eyeColor);
            eye2.setFill(eyeColor);
            mouth.setFill(mouthColor);
        }
    }

    private class Tree{
        public Tree(){

            Rectangle backGround = new Rectangle(0,0,400,400);
            backGround.setFill(Color.TRANSPARENT);
            Trees.getChildren().add(backGround);
            Rectangle grass = new Rectangle(0,300,400,150);
            grass.setFill(Color.GREEN);
            Trees.getChildren().add(grass);
            Rectangle trunk = new Rectangle(125,250, 20,70);
            trunk.setFill(Color.BROWN);
            Trees.getChildren().add(trunk);
            Ellipse leaves = new Ellipse(135,220,40,60);
            leaves.setFill(Color.GREEN);
            Trees.getChildren().add(leaves);

        }
    }


    public static void main(String[] args) {
        launch(args);
    }
}
