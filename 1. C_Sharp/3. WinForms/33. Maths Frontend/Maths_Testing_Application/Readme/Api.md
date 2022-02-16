# Maths Testing Application API Doc

*Developed by C.A Torino, TECHRAD*
* Links to TECHRAD(ZA).
    * [Website](https://techrad.co.za)
    * [Tutorials site](https://tutorials.techrad.co.za)
    * [API site](https://tutorials.techrad.co.za/api)
    * [Support site](https://support.techrad.co.za)
    * [F&Q](https://faq.techrad.co.za)

---

API documentation explaining the use of each endpoint in the `Maths Testing Application`.

Each endpoint starts with the `Function Description` and ends with an example of the response.

### Function Description

Access All Device List

-------------------

### Interface Address

```
/device/allList.do
```

### Request Method

- HTTP 
- GET 
- POST





### Response Parameters (Output)
| Parameter  |  Mode |  Maxlength  | Description  | example values  |
| :------------ | :------------ | :------------ | :------------ | :------------ |
| devList  |  List |   0  | devList  |  |
|GroupName|int|11|GroupName|Guangdongsheng_one|
|PlateIDNO|String|40|PlateIDNO|34 ZU 7295|
|SimCard|String|40|sim|1002001|
|PlateColor|int|4|PlateColor|1-blue；2-yellow，3-write，4-black|
|IMEI|String|40|IMEI|IMEI|
|VehiCompany|String|512|Company| Company|
|IDNO|String|512|IDNO|1002001|
|devSize|String|11|number of device|16399|


### Response Result Example
```json

{
result: 0,
devList: [
			{
				GroupName: "Guangdongsheng_one.1",
				PlateIDNO: "34 ZU 7295",
				SimCard: "1002001",
				PlateColor: 1,
				IMEI: "",
				VehiCompany: " Company",
				IDNO: "1002001"
			},
],
devSize: 16399
}

```
