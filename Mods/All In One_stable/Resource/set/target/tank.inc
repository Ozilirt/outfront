{selector
	{units "su-122" "bt-7" "pzjager" "ba-6" "t-60" "Rolls_Royce" "Carrier" "humber" "bt-7a" "t-20" "matildamk3"
		"T-26" "T-26A" "Pz-2F" "PZ-3L" "PZ-3N" "vickers-b" "7tp" "m8-scott" "chaffee" "Panzerflak" "SdKfz234"
		 "valentine" "t-34-76-41" "t-34-76-40" "t-34-76-43" "t-34-85" "PZ-3G" "PZ-4d" "PZ-4g" "PZ-4h" "firefly" "merchant4" "crusaderAA"
		 "PZ-5" "PZ-6" "PZ-6e" "PZ-6b" "kv-1" "kv-2" "kv-85" "kv-8" "is-2" "isu-152" "sdkfz250_3" "Jugdpanther" "merchant3"
		 "Ferdinand" "Matilda" "m10achilles" "m10wolverine" "m36" "sdkfz10-5" "StuG-3b" "m4a2" "panhard" "t-40" "ostwind" "wespe"
		"m4a3" "StuG-3f" "Stug-4g" "cromwell" "Comet" "air-bag" "mtb_d3" "m7priest" "Hummel" "panzerjager" "ft17-31" "m4a1" "t29" 
		 "7tpw" "t-26-flamethrower" "mkivcrocodile" "t-34_mineexpl" "m4a3_mineexpl" "m26Pershing" "s35" "ft17" "wirbelwind" "pz-3flam"
		"PZ3-Flamethrower" "su-100" "m3stuart" "isu-122" "t-34-57" "Kv-1E" "Nashorn" "su-85" "t-38" "merchant1" "merchant2"  "mk2crusader" 
		"m4a3e2" "m4a3-105" "STUH42" "mkivchurchill-95" "mkivchurchill" "is-1" "minenraumpanzer" "jagdtiger" "remolcador" "m4a2b"
		"Maus" "Hetzer" "sdkfz10-pak"  "mk2daimler" "m8grayhound" "m4a2flame" "sdkfz-222" "sdkfz-222e" "zis-30" "ba-11" "marder3m" "pz-5a"
		"t73" "m3" "crusader_mkII" "mk4crusader" "M45" "bison" "T-70" "M18_hellcat" "Marder" "Tetrarch" "Star"
		 "pz38tC" "Stag_Hound" "su76m" "m5a1" "kv-2_42" "pz-3f" "pz-3h" "pz-4f2" "PZ-6_42" "PZ-3j" "su-152" "t-34-f38"
		 "T48" "t-34-85-ot" "m36b1" "priest_kangaroo" "m43" "PZ-1B" "sdkfz232" "Panzerflak" "super_pershing"
		"m4a2r" "h35" "h35_pl" "charB1bis" "bergepz" "archer" "bishop" "armfishboat" "Pz-2c" "destroyer" "crusaderAA" "panzerwerfer42" "ba-11" "sdkfz251_22"
		"T19" "T48" "m36b1" "priest_kangaroo" "m43" "PZ-1B" "sdkfz232" "Panzerflak" "archer" "bishop" "ha-go" "te-ke" "ke-nu" "chi-ha47" "chi-ha57" "chi-ha120" "chi-he" "chi-nu" "chi-to" "ho-i" "ho-ni1" "ho-ni2" "ho-ro" "chi-ri" "ho-ri" "lcm"
		"ssd-mine" "ssd-flame" "lvt4" "lvt4marine" "lcvp" "pboat" "merchant1" "merchant2" "merchant3" "merchant4" "remolcador" "air-bag" "mtb_d3" "destroyer" "armfishboat" "bigfishboat" "fishboat" "merchant5" "merchant6" "merchant7" "yak5k" "shinyo" "t-class" "boat2" "ferry"
		"platforma" "platforma2" "sub-iid" "sub-viic" "air-bag2" "air-bag3" "fubukiclass" "clemson_class" "mkviichurchill" "m19" "su-76m" "ha-to" "sdkfz231"
	}
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

}
