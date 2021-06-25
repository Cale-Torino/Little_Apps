
### Function Description

Check if the server is online.

### Api Address
```HTTP
https://iq-blue.com/api/takza?type=checkserver
```
### Request Method Method

- HTTP 
- GET 
- POST

### Request Parameter (Input)
| [parameter] |  type |  if required | max length  | description  | sample value  |
| :------------ | :------------ | :------------ | :------------ | :------------ | :------------ |
| type  |  String |  not required | 255 | Check server param  |checkserver  |

### Response Parameter (Output)
| parameter     |  type         |  max length   | description   | sample value  |
| :------------ | :------------ | :------------ | :------------ | :------------ |
| result  |  Int    |   3   | Result of quary 0 means success  | 0|
| message |  String |   255 | Message of quary                 | success|
| time    |  String |   255 | Time during the day              | 2021-06-17 06:35:04pm|
| version |  String |   255 | Version of the API               | 1.0.0|
| running |  Bool   |   4   | Is the server running true,false | true|
| type    |  String |   255 | Type of API                      | takza.iq-blue.com|

### Response Results Example

```JSON
{
    "result": 0,
    "message": "success",
    "time": "2021-06-17 06:35:04pm",
    "version": "1.0.0",
    "running": true,
    "type": "takza.iq-blue.com"
}
```