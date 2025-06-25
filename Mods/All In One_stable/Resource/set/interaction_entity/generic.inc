(define "hide_mp"
	(mod "mp"
		{delay %0 %1
			{delete}
		}
	)
)
{"flesh"
	{friction 1.0}
	{restitution 0.2}
	{on bullet_hit
		{if not under_water
			{if bullet "flame"
				{fire radius 1.5 time 2 heating 20 effector followowner}
			else bullet "zenite"
				{spawn "ex_air_norm"}
			else bullet "shell fg"
				{spawn "ex_air_big"}
			else bullet "mortar"
				{spawn "ex_air_big"}
			else bullet "bazooka"
				{spawn "ex_air_big"}
			}
		}
	}
}

{"steel"
	{friction  0.5}
	{restitution 0.7}
	{on bullet_hit
		{if not under_water
			{if bullet "flame"
				{fire radius 1.5 time 2 heating 20 effector followowner}
			else bullet "bullet"
				{spawn "metal_hit_bul"}
				{spawn "ex_air_sm"}
			else bullet "zenite"
				{spawn "metal_hit_bul"}
				{spawn "ex_air_sm"}
			else bullet "shell small"
;				{spawn "ex_air_big"}
				{spawn "metal_hit_br_small"}
			else bullet "shell"
;				{spawn "ex_air_big"}
				{spawn "metal_hit_br"}
			else bullet "mortar"
;				{spawn "ex_air_big"}
				{spawn "metal_hit_br"}
			}
		}
	}
}

{"wood"
	{friction  0.5}
	{restitution 0.7}
	{on bullet_hit
		{if not under_water
			{if bullet "flame"
				{fire radius 1.5 time 2 heating 20 effector followowner}
			else bullet "bullet"
				{spawn "wood_hit_bul"}
				{spawn "ex_air_sm"}
			else bullet "zenite"
				{spawn "wood_hit_bul"}
				{spawn "ex_air_sm"}
			else bullet "shell small"
				{spawn "wood_hit_br_small"}
			else bullet "shell"
				{spawn "wood_hit_br"}
			else bullet "mortar"
				{spawn "wood_hit_br"}
			}
		}
	}
}

{"concrete"
	{friction  0.5}
	{restitution 0.7}
	{on bullet_hit
		{if not under_water
			{if bullet "flame"
				{fire radius 1.5 time 2 heating 20 effector followowner}
			else bullet "bullet"
				{spawn "stone_hit_bul"}
				{spawn "ex_air_sm"}
			else bullet "zenite"
				{spawn "stone_hit_bul"}
				{spawn "ex_air_sm"}
			else bullet "shell small"
			 	{spawn	"stone_hit_br_small"}
			else
			 	{spawn	"stone_hit_br"}
			}
		}
	}
}
