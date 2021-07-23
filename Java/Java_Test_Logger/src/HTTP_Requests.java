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

		    try (InputStream is = http.getInputStream()) {
		        final byte[] buf = new byte[1024];
		        final StringBuilder b = new StringBuilder();
		        int read = 0;
		        while ((read = is.read(buf)) != -1) 
		        {
		           b.append(new String(buf, 0, read));
		        }
				return b.toString();
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
		    try (InputStream is = http.getInputStream()) {
		        final byte[] buf = new byte[1024];
		        final StringBuilder b = new StringBuilder();
		        int read = 0;
		        while ((read = is.read(buf)) != -1) 
		        {
		           b.append(new String(buf, 0, read));
		        }
		        
		        //return " *** HTTP_Request=>Response: " + http.getResponseMessage();
		        return b.toString();
		    }
		    
		}
		catch(Exception exception)
		{
			return "Error:" + exception;
		}

    }

}
