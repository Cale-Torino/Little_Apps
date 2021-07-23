import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;

/**
 * 
 */

/**
 * @author C.A Torino
 *
 */
public class LoggerClass {
	final static DateFormat dateFormat = new SimpleDateFormat("yyyy-dd-M--HH-mm-ss");
	final static Date date = new Date();
	static String Fdate = dateFormat.format(date);
  //Create log file log. file
	final static File AppPath = new File(main.class.getProtectionDomain().getCodeSource().getLocation().getPath());
    private static String LogFile = AppPath.toString() + "\\Logs\\main_java_Test_" + Fdate + ".log";
  
	public static void WriteLine(String txt)
  {
      try
      {
  	    LocalDateTime myDateObj = LocalDateTime.now();
  	    DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
      	Files.write(Paths.get(LogFile), ("["+myDateObj.format(myFormatObj)+"] : " + txt + System.lineSeparator()).getBytes(),StandardOpenOption.CREATE,StandardOpenOption.APPEND);
      }
      catch (Exception ex)
      {
      	System.out.println("Error: Could Not Append Text To Log File");
          return;
      }
   }
	
	public static void DeleteLog()
  {
      try
      {
    	  //Delete the log file
          System.out.println("Deleting log file");
    	  File myObj = new File(LogFile); 
    	  if (myObj.delete()) { 
    	    System.out.println("Deleted the file: " + myObj.getName());
    	  } else {
    	    System.out.println("Error: Failed to delete the file.");
    	  } 
      }
      catch (Exception ex)
      {
      	System.out.println("Error: Could Not Delete Log File");
          return;
      }
   }
  
}