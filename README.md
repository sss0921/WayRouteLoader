### About WayRouteLoader

* 航路的存储主要采用JSON格式。

航路的存储格式为：

```
{
	"items": [
		{
			"type": "simple",
			"sequence:" 0,
			"params": [
				 0.000000,   //经度
				 0.000000,   //纬度
				 0,		     //高度
				 0.0,	     //速度
				 0,			 //半径
				 0x00		 //特征字
			]		
		},
		{
			"type": "survey",
			"sequence": 1,
			"camera": {
				"cameraName": "custom camera",
				"imageDensity": 0,
                "imageHeight:": 0,
                "imageWidth:": 0
			},
			"items": {
				"num": 2
				"params": [
					[
					 	0.000000,  //经度
						0.000000,  //纬度
						0,		   //高度
						0.0,	   //速度
						0,		   //半径
						0x00	   //特征字
					],
					[
						0.000000,  //经度
					 	0.000000,  //纬度
					 	0,         //高度
					 	0.0,	   //速度
					 	0,		   //半径
					 	0x00	   //特征字
					]
				]	
			}
		}
	]
}
```
