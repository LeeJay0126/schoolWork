package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
//        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
//        primaryStage.setTitle("Hello World");
//        primaryStage.setScene(new Scene(root, 300, 275));
//        primaryStage.show();

        //Test case 1:
        System.out.println("Test case 1:");
        Rectangle rec1= new Rectangle();
        rec1.setWidth(10);
        rec1.setHeight(12);
        System.out.println(rec1.getWidth());
        System.out.println(rec1.getHeight());
        System.out.println(rec1.getArea());
        System.out.println(rec1.getCircumference());

        // Test case 2:
        System.out.println("Test case 2:");
        Rectangle rec2= new Rectangle(8,5);
        System.out.println(rec2.getWidth());
        System.out.println(rec2.getHeight());
        System.out.println(rec2.getArea());
        System.out.println(rec2.getCircumference());
    }


    public static void main(String[] args) {
        launch(args);
    }
}
