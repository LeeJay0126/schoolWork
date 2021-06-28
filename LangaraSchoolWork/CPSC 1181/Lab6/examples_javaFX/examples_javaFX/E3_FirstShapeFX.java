import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.text.Text;
import javafx.scene.shape.Rectangle;

public class E3_FirstShapeFX extends Application {
	@Override
	public void start(Stage primaryStage) {

		Pane root = new Pane();
		
		Text hello = new Text(50, 100, "Hello, World!");
		Rectangle r = new Rectangle(45, 105, 200, 10);
		
		root.getChildren().addAll(hello, r);
		
		Scene scene = new Scene(root, 400, 200);
		primaryStage.setTitle("JavaFX Example");
		primaryStage.setScene(scene);
		primaryStage.show();
	}

	public static void main(String[] args) {
		Application.launch(args);
	}
	
}