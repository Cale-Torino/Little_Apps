import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.concurrent.TimeUnit;

/**
 * 
 */

/**
 * @author User501
 *
 */
public class RaspberryTestMain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
    	LogWindow(" ***********************************");
    	LogWindow(" *** @author: C.A Torino         ***");
    	LogWindow(" *** @initial_date: 22 July 2021 ***");
    	LogWindow(" ***********************************");
    	LogWindow("");
		//LoggerClass Log = new LoggerClass();
		Ini();
        LogWindow(" *** Ini Complete [Main] ***");

		//String Request_JSON = HTTP_RequestsClass.HTTP_Request_JSON("https://techrad.co.za/java/test/java_in_json.php?API_KEY=java1234&USERNAME=java&DATA=testing_data", "{\"username\":\"root\",\"password\":\"password\"}");
		LocalDateTime myDateObj = LocalDateTime.now();
  	    DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy_HH:mm:ss");
		String HTTP_Request = HTTP_RequestsClass.HTTP_Request("https://techrad.co.za/java/test/java_in.php?API_KEY=java1234&USERNAME=java&DATA=" + myDateObj.format(myFormatObj) );
		LogWindow(" *** HTTP_Request=>Response: " + HTTP_Request);
		//LogWindow(" *** HTTP_Request_JSON=>Response: " + Request_JSON);
		LoggerClass.WriteLine("Raspberypi time: "+myDateObj.format(myFormatObj));
		LoggerClass.WriteLine("Server reply HTTP_Request:" + HTTP_Request);
		//LogWindow(" *** HTTP_Request=>Response: " + result);
		//SleepFunc();
		//LoggerClass.DeleteLog();
	}
	
	public static void SleepFunc()
    {
		try
		{
			TimeUnit.SECONDS.sleep(10);
			//TimeUnit.MINUTES.sleep(1);
		}
		catch(InterruptedException exception)
		{
		    //Thread.currentThread().interrupt();
		    LogWindow("Error:" + exception);
		}

    }
	
	public static void LogWindow(String txt)
    {
		DateFormat dateFormat = new SimpleDateFormat("yyyy/dd/M HH:mm:ss");
		Date date = new Date();
        System.out.println("[" + dateFormat.format(date) + "] : " + txt);
    }
	
	public static void Ini()
	{
	    try
	    {
	        //Initiate the application by calling these methods
	        CreateFolder();
	    }
	    catch (Exception ex)
	    {
	        LogWindow("Ini Error!");
	        return;
	    }
	}

	public static void CreateFolder()
	{
	    try
	    {
	        //Create the folders used by the application
	    	final File f = new File(RaspberryTestMain.class.getProtectionDomain().getCodeSource().getLocation().getPath());
	    	Files.createDirectories(Paths.get(f.toPath()+"/Logs"));
	    	LogWindow(" *** Application Start [Main] ***");
	    	LogWindow(" *** CreateDirectory Success [Main] ***");
	    }
	    catch (Exception ex)
	    {
	    	LogWindow("Create Folder Error!");
	        return;
	    }
	}
}
