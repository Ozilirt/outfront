{selector
	{units
		"bt-7" "bt-7a" "T-26" "Pz-2F" "vickers-b" "m8-scott" "chaffee" "Panzerflak"
		"SdKfz234" "t-34-76-41" "t-34-85" "PZ-3G" "PZ-4d" "PZ-4g"
		"PZ-5" "PZ-6" "PZ-6e" "PZ-6b" "kv-1" "kv-2" "kv-85" "is-2"
		"Jugdpanther" "Ferdinand" "Matilda" "m10achilles"
		"sdkfz10-5" "StuG-3b" "m4a2" "m4a3" "StuG-40b" "Stug-4g" "cromwell"
   	    "air-bag" "mtb_d3" "m7priest" "Hummel"}

	{group
		{select {weapon "ap"}}
		{select {weapon "fg"}}

		{sort {weapon "ap"} {attacking}}
		{sort {weapon "ap"} {threating}}
		{sort {weapon "fg"} {attacking}}
		{sort {weapon "ap"}}
		{sort {weapon "fg"} {threating}}
		{sort {weapon "fg"}}
		{sort time_to_aim}
	}

	{group
		{sort {class tank}}
		{sort {class car}}
		{sort time_to_aim}
	}



;	{group
;		{select {weapon "ap"}}
;
;		{sort {attacking}}
;		{sort {threating}}
;		{sort {inrange}}
;	}

;	{group
;		{select {weapon "fg"}}
; 
;		{sort {attacking}}
;		{sort {threating}}
;		{sort {inrange}}
;	}

;	{group
;		{select {weapon}}
; 
;		{sort {attacking}}
;		{sort {threating}}
;		{sort {inrange}}
;	}

}
