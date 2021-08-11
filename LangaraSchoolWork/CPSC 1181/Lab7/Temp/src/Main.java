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

    /**
     * declared private variables
     */
    private RadioButton degree0;
    private RadioButton degree90;
    private RadioButton degree180;
    private RadioButton degree270;
    private ToggleGroup degrees;

    private CheckBox rain;
    private CheckBox smile;

    private Button textButton;

    private Pane Trees;

    private Circle sunBase;
    private Circle eye1;
    private Circle eye2;
    private Arc mouth;
    private Group smiley;

    private Arc purple;
    private Arc indigo;
    private Arc blue;
    private Arc green;
    private Arc yellow;
    private Arc orange;
    private Arc red;

    private Text message;
    private TextField textField;

    private Group treeWithLeaves;

    /**
     * start method
     * generates panes, hbox, vbox, scene and stage necessary for the visuals
     * and links buttons and text fields to event handling methods
     * @param primaryStage
     * @throws Exception
     */
    @Override
    public void start(Stage primaryStage) throws Exception{

        Text background = new Text("Background");
        background.setFont(Font.font("Arial",14));
        rain = new CheckBox("rainbow");
        smile = new CheckBox("smile");

        HBox rainOrSmile = new HBox(10);
        rainOrSmile.getChildren().addAll(rain,smile);

        CheckBoxesListener smileRainListener = new CheckBoxesListener();
        smile.setOnAction(smileRainListener);
        rain.setOnAction(smileRainListener);


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

        degrees.selectToggle(degree0);

        RadioButtonListener rblistener = new RadioButtonListener();

        degree0.setOnAction(rblistener);
        degree90.setOnAction(rblistener);
        degree180.setOnAction(rblistener);
        degree270.setOnAction(rblistener);


        VBox radioButtons = new VBox(10,degree0,degree90,degree180,degree270);
        radioButtons.setPadding(new Insets(20,5,20,5));

        VBox secondVbox = new VBox(firstVbox,radioButtons);

        Text caption = new Text("Caption");
        caption.setFont(Font.font("Arial",14));
        textField = new TextField("");
        textField.setPrefWidth(100);
        textButton = new Button("Change Text");

        CaptionTextListener updateText = new CaptionTextListener();
        textButton.setOnAction(updateText);
        textField.setOnAction(updateText);

        VBox textVbox = new VBox(15,caption,textField,textButton);
        textVbox.setPadding(new Insets(20,5,0,5));
        textVbox.setAlignment(Pos.CENTER);

        VBox thirdVbox = new VBox(secondVbox, textVbox);

        Trees = new Pane();

        sunBase = new Circle(330, 60, 30);
        eye1 = new Circle(345, 45, 5);
        eye2 = new Circle(315, 45, 5);
        mouth = new Arc(330, 65, 15, 15, 180, 180);
        //Have to learn how to draw a proper arc
        mouth.setType(ArcType.CHORD);

        sunBase.setFill(Color.YELLOW);
        eye1.setFill(Color.BLACK);
        eye2.setFill(Color.BLACK);
        mouth.setFill(Color.BLACK);

        smiley = new Group(sunBase,eye1,eye2,mouth);

        Trees.getChildren().add(smiley);

        smiley.setVisible(false);

        int radiusX = 180;
        int radiusY = 200;


        red = new Arc(200,300,176,200,0,180);
        red.setFill(Color.TRANSPARENT);
        red.setStroke(Color.TRANSPARENT);
        red.setStrokeWidth(4);

        orange = new Arc(200,300,180,204,0,180);
        orange.setFill(Color.TRANSPARENT);
        orange.setStroke(Color.TRANSPARENT);
        orange.setStrokeWidth(4);

        yellow = new Arc(200,300,184,208,0,180);
        yellow.setFill(Color.TRANSPARENT);
        yellow.setStroke(Color.TRANSPARENT);
        yellow.setStrokeWidth(4);

        green = new Arc(200,300,188,212,0,180);
        green.setFill(Color.TRANSPARENT);
        green.setStroke(Color.TRANSPARENT);
        green.setStrokeWidth(4);

        blue = new Arc(200,300,192,216,0,180);
        blue.setFill(Color.TRANSPARENT);
        blue.setStroke(Color.TRANSPARENT);
        blue.setStrokeWidth(4);

        indigo = new Arc(200,300,196,220,0,180);
        indigo.setFill(Color.TRANSPARENT);
        indigo.setStroke(Color.TRANSPARENT);
        indigo.setStrokeWidth(4);

        purple = new Arc(200,300,200,224,0,180);
        purple.setFill(Color.TRANSPARENT);
        purple.setStroke(Color.TRANSPARENT);
        purple.setStrokeWidth(4);



        Group rainbow = new Group(red,orange,yellow,green,blue,indigo,purple);
        Trees.getChildren().add(rainbow);

        Tree tree = new Tree();

        message = new Text(30,400,"");
        message.setFont(Font.font("Arial",40));
        message.setFill(Color.YELLOW);

        Trees.getChildren().add(message);

        HBox finalBox = new HBox(thirdVbox,Trees);

        Scene scene = new Scene(finalBox);

        primaryStage.setTitle("CPSC1181 Lab 7");
        primaryStage.setScene(scene);
        primaryStage.setResizable(false);
        primaryStage.show();


    }

    /**
     *Class RadioButtonListen
     * this class implements EventHandler interface
     * depending on which radio button is selected, it will rotate group treeWithLeaves
     * (group that includes tree trunk and leaves)
     * by set amount of degrees listed on the button
     */
    private class RadioButtonListener implements  EventHandler<ActionEvent>{

        /**
         * method handle
         * Used setRotate() on the group object if
         * one of the buttons were selected. When program starts,
         * default selected button is degree0.
         * @param event
         */
        @Override
        public void handle(ActionEvent event){
            if(degree0.isSelected()){

                treeWithLeaves.setRotate(0);

            }else if(degree90.isSelected()){

                treeWithLeaves.setRotate(90);

            }else if(degree180.isSelected()){

                treeWithLeaves.setRotate(180);

            }else if(degree270.isSelected()){

                treeWithLeaves.setRotate(270);

            }
        }
    }

    /**
     * class Caption TextListener
     * implements EventHandler interface
     */
    private class CaptionTextListener implements  EventHandler<ActionEvent>{

        /**
         * fetches text user wants to change the text into from TextField textField.
         * default initial message is empty string.
         * sets message (Text object that will be displayed) to the text fetched
         * @param event
         */
        @Override
        public void handle(ActionEvent event) {
            message.setText(textField.getText());
        }
    }

    /**
     * Class CheckBoxesListener
     * implements EventHandler interface
     */
    private class CheckBoxesListener implements EventHandler<ActionEvent> {

        /**
         * checking rainbow button will make rainbow visible from the right side of the screen
         * checking smiley button will make a smiley face visible from the right side of the screen
         *
         * for rainbow, I tried not to use setVisible() function as a challenge.
         * I set the default color of the fills for the rainbow transparent, then gave it it's intended
         * color when the check box is checked.
         *
         * for smiley, grouped the members of the group smiley and used setVisible()
         *
         * @param event
         */
        @Override
        public void handle(ActionEvent event) {

            Color redColor = Color.TRANSPARENT;
            Color orangeColor = Color.TRANSPARENT;
            Color yellowColor = Color.TRANSPARENT;
            Color greenColor = Color.TRANSPARENT;
            Color blueColor = Color.TRANSPARENT;
            Color indigoColor = Color.TRANSPARENT;
            Color purpleColor = Color.TRANSPARENT;

            Boolean visible = false;

            if(smile.isSelected()) {

                visible = true;

            }

            if(rain.isSelected()){
                redColor = Color.RED;
                orangeColor = Color.ORANGE;
                yellowColor = Color.YELLOW;
                greenColor = Color.GREEN;
                blueColor = Color.BLUE;
                indigoColor = Color.INDIGO;
                purpleColor = Color.PURPLE;
            }

            red.setStroke(redColor);
            orange.setStroke(orangeColor);
            yellow.setStroke(yellowColor);
            green.setStroke(greenColor);
            blue.setStroke(blueColor);
            indigo.setStroke(indigoColor);
            purple.setStroke(purpleColor);

            smiley.setVisible(visible);

        }
    }

    /**
     * class Tree
     * used this class to add default objects to the right side of the screen
     * as well as grouping tree
     */
    private class Tree{
        /**
         * generated default objects that will be displayed.
         * grouped tree to use setRotate() later on.
         *
         */
        public Tree(){

            Rectangle backGround = new Rectangle(0,0,400,400);
            backGround.setFill(Color.TRANSPARENT);
            Trees.getChildren().add(backGround);
            Rectangle grass = new Rectangle(0,300,400,150);
            grass.setFill(Color.GREEN);
            Trees.getChildren().add(grass);
            Rectangle trunk = new Rectangle(125,250, 20,70);
            trunk.setFill(Color.BROWN);
            Ellipse leaves = new Ellipse(135,220,40,60);
            leaves.setFill(Color.GREEN);

            treeWithLeaves = new Group(trunk,leaves);

            Trees.getChildren().add(treeWithLeaves);

        }
    }


    /**
     * main method
     * @param args
     */
    public static void main(String[] args) {
        launch(args);
    }
}

