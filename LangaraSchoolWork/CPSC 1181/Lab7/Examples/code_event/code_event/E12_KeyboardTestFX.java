

import javafx.application.Application;
import javafx.scene.input.KeyEvent;
import javafx.event.EventHandler;
import javafx.scene.input.KeyCode;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.text.Text;



public class E12_KeyboardTestFX extends Application
{
   
   private Scene scene;
   private Pane root;
   public void start(Stage stage)
   {

      Text msg = new Text(30,30,"push a symbol key\nor up/down/left/right/delete keys\ncombined with shift key");
      root = new Pane(msg);
      root.setOnKeyPressed(new KeyboardPressedHandler());
      root.setOnKeyTyped(new KeyboardClickedHandler());
         
      scene = new Scene(root);
      root.setPrefSize(250, 100);
      stage.setScene(scene);
      stage.setTitle("Keyboard Test");
      stage.show();
      root.requestFocus();// Important
   }
   private class KeyboardPressedHandler implements EventHandler<KeyEvent> {
      @Override
      public void handle(KeyEvent event) {
            KeyCode code = event.getCode();
            boolean shift = event.isShiftDown();
            if (shift)
               System.out.print("shift + ");   
            if (code == KeyCode.DELETE)
               System.out.println("Delete");
            else if (code == KeyCode.UP)
               System.out.println("Up");
            else if (code == KeyCode.DOWN)
               System.out.println("Down");
            else if (code == KeyCode.LEFT)
               System.out.println("Left");
            else if (code == KeyCode.RIGHT)
               System.out.println("Right");

         
      }
   }  
   private class KeyboardClickedHandler implements EventHandler<KeyEvent> {
      @Override
      public void handle(KeyEvent event) {
            String ch = event.getCharacter();
            System.out.println(ch);
            
         
      }
   }  
}