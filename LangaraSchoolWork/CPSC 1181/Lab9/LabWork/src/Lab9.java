import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
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

public class Lab9 extends Application {
    private VBox root;
    public static final String START_DATE = "1/1/2000";
    private TextField dStartDate;
    private TextField dEndDate;
    private DateVerifier verifier;

    public Lab9() {
    }

    public void start(Stage var1) {
        this.root = new VBox(5.0D);
        this.verifier = new DateVerifier();
        this.createStartFields();
        this.createEndFields();
        this.createButton();
        Scene var2 = new Scene(this.root);
        var1.setTitle("Date Counter");
        var1.setScene(var2);
        var1.show();
    }

    private void createStartFields() {
        Label var1 = new Label("Start Date: ");
        this.dStartDate = new TextField("1/1/2000");
        HBox var2 = new HBox(5.0D, new Node[]{var1, this.dStartDate});
        VBox var10000 = this.root;
        VBox.setMargin(var2, new Insets(10.0D, 10.0D, 10.0D, 10.0D));
        this.root.getChildren().add(var2);
    }

    private void createEndFields() {
        Label var1 = new Label("End Date: ");
        String var2 = LocalDateTime.now().getDayOfMonth() + "/" + LocalDateTime.now().getMonthValue() + "/" + LocalDateTime.now().getYear();
        this.dEndDate = new TextField(var2);
        HBox var3 = new HBox(5.0D, new Node[]{var1, this.dEndDate});
        VBox var10000 = this.root;
        VBox.setMargin(var3, new Insets(10.0D, 10.0D, 10.0D, 10.0D));
        this.root.getChildren().add(var3);
    }

    private void createButton() {
        Button var1 = new Button("Count");
        this.root.getChildren().add(var1);
        this.root.setAlignment(Pos.CENTER);
        VBox var10000 = this.root;
        VBox.setMargin(var1, new Insets(10.0D, 10.0D, 10.0D, 10.0D));
        var1.setOnAction(new Lab9.MyEventHandler());
    }

    public static void main(String[] var0) {
        Application.launch(var0);
    }

    private class MyEventHandler implements EventHandler<ActionEvent> {
        private MyEventHandler() {
        }

        public void handle(ActionEvent var1) {
            String var2 = Lab9.this.dStartDate.getText();
            String var3 = Lab9.this.dEndDate.getText();
            String var4 = "";

            try {
                LocalDate var5 = Lab9.this.verifier.verify(var2, "Start Date: ");
                LocalDate var6 = Lab9.this.verifier.verify(var3, "End Date: ");
                Period var7 = Period.between(var5, var6);
                long var8 = ChronoUnit.DAYS.between(var5, var6);
                String var10 = var7.getDays() + " days\n";
                var10 = var10 + var7.getMonths() + " Months\n";
                var10 = var10 + var7.getYears() + " years\n";
                var10 = var10 + var8 + " total days";
                this.showDialog(var10);
            } catch (DateTimeException var11) {
                var4 = var11.getMessage();
                this.showDialog(var4);
            } catch (CPSC1181Exception var12) {
                var4 = var12.getMessage();
                this.showDialog(var4);
            }

        }

        private void showDialog(String var1) {
            Stage var2 = new Stage();
            var2.initModality(Modality.APPLICATION_MODAL);
            VBox var3 = new VBox(20.0D);
            var3.getChildren().add(new Text(var1));
            Scene var4 = new Scene(var3, 300.0D, 200.0D);
            var2.setScene(var4);
            var2.show();
        }
    }
}

