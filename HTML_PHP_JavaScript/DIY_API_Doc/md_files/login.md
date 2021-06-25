
### Function Description

Login to the account.

### Api Address
```HTTP
https://iq-blue.com:8080/StandardApiAction_login.action?account=admin&password=admin123
```

### Request Method Method

- HTTP 
- GET 
- POST

### Request Parameter (Input)
| parameter |  type |  if required | max length  | description  | sample value  |
| :------------ | :------------ | :------------ | :------------ | :------------ | :------------ |
| account  |  String |  required | 255 | account name  |admin  |
| password  |  String |  required | 255 | account password  |admin123  |

### Response Parameter (Output)
| parameter     |  type         |  max length   | description   | sample value  |
| :------------ | :------------ | :------------ | :------------ | :------------ |
| result  |  Int    |   3   | Result of quary 0 means success  | 0|
| jsession |  String |   255 | Jsession               | cf6b70a3c82b43928ab6bbddce336222|

### Response Results Example

```JSON
{
  "result": 0,
  "jsession": "cf6b70a3c82b43928ab6bbddce336222"
}
```