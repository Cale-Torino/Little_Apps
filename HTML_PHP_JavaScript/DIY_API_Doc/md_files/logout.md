
### Function Description

Logout of the account.

### Api Address
```HTTP
https://iq-blue.com:8080/StandardApiAction_logout.action?jsession=cf6b70a3c82b43928ab6bbddce336222
```
### Request Method Method

- HTTP 
- GET 
- POST

### Request Parameter (Input)
| [parameter] |  type |  if required | max length  | description  | sample value  |
| :------------ | :------------ | :------------ | :------------ | :------------ | :------------ |
| Jsession  |  String | required | 255 | Jsession  |cf6b70a3c82b43928ab6bbddce336222  |

### Response Parameter (Output)
| parameter     |  type         |  max length   | description   | sample value  |
| :------------ | :------------ | :------------ | :------------ | :------------ |
| result  |  Int    |   3   | Result of quary 0 means success  | 0|
| message |  String |   255 | Message of quary                 | success|

### Response Results Example

```JSON
{
  "result": 0
}
```