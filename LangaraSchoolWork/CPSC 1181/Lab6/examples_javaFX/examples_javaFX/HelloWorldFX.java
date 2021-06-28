
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
   @version 1.4 2017-12-23
   @author Cay Horstmann
*/
public class HelloWorldFX extends Application {
   public void start(Stage stage) {
      Text message = new Text(75, 100,"Hello JavaFX");
      Pane root = new Pane(message);
      root.setPrefSize(300, 200);
      Scene scene = new Scene(root);
      stage.setScene(scene);
      stage.setTitle("Hello");
      stage.show();
   }

   public static void main(String[] args) {
        launch(args);
   }
}


