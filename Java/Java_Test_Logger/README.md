# Java_Test_Logger

Java is relatively easy to use from a C# background.

Both languages are c-styled and sometimes it can be incredibly easy to copy and convert methods.

## Main App Class

```Java
import java.io.File;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.TimeUnit;

/**
 * https://stackoverflow.com/questions/24104313/how-do-i-make-a-delay-in-java
 */

/**
 * @author C.A Torino
 *
 */
public  class main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
    	LogWindow(" ***********************************");
    	LogWindow(" *** @author: C.A Torino ***");
    	LogWindow(" *** @initial_date: 22 July 2021 ***");
    	LogWindow(" ***********************************");
    	LogWindow("");
		//LoggerClass Log = new LoggerClass();
		Ini();
        LogWindow(" *** Ini Complete [Main] ***");
		LoggerClass.WriteLine("Test write to log file");
		LoggerClass.WriteLine("Test write to log file again");
		
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
	    	Files.createDirectories(Paths.get(f.toPath()+"\\Logs"));
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
```



## LoggerClass Class

```Java
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
```


## HTTP_Requests Class

```Java
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;

/**
 * 
 */

/**
 * @author C.A Torino
 *
 */
public class HTTP_Requests {
	
	public static String HTTP_Request_JSON(String urlstring, String JSON)
    {
		try
		{
			URL url = new URL(urlstring);
			HttpURLConnection http = (HttpURLConnection)url.openConnection();
			byte[] out = JSON.getBytes();
			int length = out.length;

			http.setFixedLengthStreamingMode(length);
			http.setRequestProperty("Content-Type", "application/json; charset=UTF-8");
			http.setDoOutput(true);
			http.connect();
			try(OutputStream os = http.getOutputStream()) {
			    os.write(out);
			}
			//try get the response
		    try (InputStream is = http.getInputStream()) {
		        final byte[] buf = new byte[1024];
		        final StringBuilder b = new StringBuilder();
		        int read = 0;
		        while ((read = is.read(buf)) != -1) 
		        {
		           b.append(new String(buf, 0, read));
		        }
				return b.toString();//write response
		    }

		}
		catch(Exception exception)
		{
		    return "Error:" + exception.toString();
		}

    }
	
	public static String HTTP_Request(String urlstring)
    {
		try
		{
			URL url = new URL(urlstring);
			HttpURLConnection http = (HttpURLConnection)url.openConnection();
			http.setRequestMethod("POST"); // PUT is another valid option
			http.setDoOutput(true);
			http.connect();
			//try get the response
		    try (InputStream is = http.getInputStream()) {
		        final byte[] buf = new byte[1024];
		        final StringBuilder b = new StringBuilder();
		        int read = 0;
		        while ((read = is.read(buf)) != -1) 
		        {
		           b.append(new String(buf, 0, read));
		        }
		        
		        //return " *** HTTP_Request=>Response: " + http.getResponseMessage();
		        return b.toString();//write response
		    }
		    
		}
		catch(Exception exception)
		{
			return "Error:" + exception;
		}

    }

}

```