{vision "vision"
	{desc "vision"}
	{level "farseer"
		{uncover 2}
		{h_fov 100}
		{v_fov 120}
		{human 
			{stay  70}
			{squat 50}
			{crawl 45}
		}
		{actor "vehicle" 80}
		{actor "marine" 60}
		{actor 60}
	}	
	{level "human"
		{uncover 2}
		{h_fov 160}
		{v_fov 120}
		{human
			{stay 35}
			{squat 25}
			{crawl 15}
		}
		{actor "tank" 70}
		{actor "vehicle" 60}
		{actor 40}
	}
	{level "mp_soldier"
		{uncover 10}
		{h_fov 160}
	    {human 40
	    	{crawl 25}
	    }
	    {actor "vehicle" 70}
		{v_fov 120}
		{actor 40}
		{fog_range 40}
		{fog_fov 120}
	}
	{level "mp_officer"
		{uncover 15}
		{h_fov 160}
	    {human 60
	    	{crawl 30}
	    }
	    {actor "vehicle" 70}
		{v_fov 120}
		{actor 60}
		{fog_range 40}
		{fog_fov 120}
	}
	{level "mp_specnaz"
		{uncover 12}
		{h_fov 160}
		{v_fov 120}
	    {human 50
	    	{crawl 40}
	    }
	    {actor "vehicle" 70}
		{actor 50}
		{fog_range 40}
		{fog_fov 160}
	}
	{level "mp_sniper"
		{uncover 5}
		{h_fov 30}
		{v_fov 120}
	    {human 70
	    	{crawl 25}
	    }
	    {actor "vehicle" 70}
		{actor 50}
		{fog_range 70}
		{fog_fov 30}
	}
}
