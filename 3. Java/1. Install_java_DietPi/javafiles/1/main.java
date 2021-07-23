import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.util.concurrent.TimeUnit;

//https://stackoverflow.com/questions/24104313/how-do-i-make-a-delay-in-java
//https://stackoverflow.com/questions/3324717/sending-http-post-request-in-java


/**
 * @author C.A Torino
 *
 */
public  class main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) {
    	LogWindow(" ***********************************");
    	LogWindow(" *** @author: C.A Torino         ***");
    	LogWindow(" *** @initial_date: 22 July 2021 ***");
    	LogWindow(" ***********************************");
    	LogWindow("");
		//LoggerClass Log = new LoggerClass();
		Ini();
        LogWindow(" *** Ini Complete [Main] ***");
		LoggerClass.WriteLine("Test write to log file");
		LoggerClass.WriteLine("Test write to log file again");
		String Request_JSON = HTTP_Requests.HTTP_Request_JSON("https://techrad.co.za/java/test/java_in.php?API_KEY=java1234&USERNAME=java&DATA=testing_data", "{\"username\":\"root\",\"password\":\"password\"}");
		LocalDateTime myDateObj = LocalDateTime.now();
  	    DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy_HH:mm:ss");
		String HTTP_Request = HTTP_Requests.HTTP_Request("https://techrad.co.za/java/test/java_in.php?API_KEY=java1234&USERNAME=java&DATA=" + myDateObj.format(myFormatObj) );
		LogWindow(" *** HTTP_Request=>Response: " + HTTP_Request);
		LogWindow(" *** HTTP_Request_JSON=>Response: " + Request_JSON);
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
	    	final File f = new File(main.class.getProtectionDomain().getCodeSource().getLocation().getPath());
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



