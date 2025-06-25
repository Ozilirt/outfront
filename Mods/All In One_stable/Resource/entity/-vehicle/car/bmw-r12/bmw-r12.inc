;SDL
	(include "/properties/shadow/moto.inc"  scX(0.5) scY(0.6) psfX(-7) psfY(0))
	(include "/properties/selection/vehicle.inc"  scale(0.7))
	{Props "emit_on_attack" "explosion_throw_crew"}
	{PatherId "vehicle.small"}

	{TexMods
		{"ambush1" "1"}
		{"soviet"  "2"}
		{"usa" "3"}
		{"gb" "4"}
	}
	{sensor
		{Visor "main"
			{bone "visor1"}
		}
		{Visor "crew"
			{vision "moto-crew"}
			{bone "visor2"}
		}  
	}
	
	{Placer
		{place "driver"		{Group "driver"}	{LinkBone "driver"}		{visor "main"} {turnoff {sensor}{shadow}}}
		{place "gunner"		{worker charger}	{LinkBone "gunner"}		{visor "crew"} {turnoff {sensor}{shadow}}}
		{place "passenger" 	{Group "driver"} 	{LinkBone "passenger"}	{visor "crew"} {turnoff {sensor}{shadow}}}
	}
	{boarder
		{door "emit1"}
		{door "emit2"}
		{door "emit3"}

		{anm "driver" {forward  {end "seat_driver_moto"}}}
		{anm "gunner" {forward  {end "seat_gunner_moto"}}}
		{anm "passenger" {forward  {end "seat_passenger"}}}

		{link "emit1" "driver"    {anm "driver"} {forward putoff} {reverse puton}}
		{link "emit2" "passenger" {anm "passenger"} {forward putoff} {reverse puton}}
		{link "emit3" "gunner"	  {anm "gunner"} {forward putoff} {reverse puton}}
	}

	("wheel" args "wheel1")
	("wheel" args "wheel2")
	("wheel" args "wheel3")

	{extender "inventory"
		{weapon "mgun"
			{mask "weapon mgun"}
		}
		{Box
			{item  "ammo mgun" 200 }
		}
	}
	{mass 1500}
	{Chassis
		{Locomotion ("locomotion")
			{MaxSpeed	40	}		; максимальная скорость, kmph
			{StartTime	10	}		; время разгона до макс. скорости с 0, seconds
			{BrakeTime	2	}		; время торможения с макс. скорости до 0, seconds
			{StopTime	4	}		; время остановки после отключения двигателя с макс. скорости до 0, seconds
			{TurnRadius	2	}		; мин. радиус разворота, meter
			{Gears		0.35 0.5 0.7 1.0} ; передаточные коэф-ты коробки передач
			{RearGears	0.33 0.5}	; передаточные коэф-ты коробки передач
			{SteerOn	40}			; скорость поворота колес, градусов в секунду
			{SteerOff	40}         ; скорость возврата колес в исх. состояние, градусов в секунду
			{SplineRadius 2}		; ограничение радиуса поворота на сплайнах, метров
		}	
		{FuelBag
			{volume 50 }	; liters
			{rate	10 }   	; liters per kilometer
			{remain 50 }
			{fuel "fuel"}
		}
		{speed
			{Slow	7	}	; km/h
		}
	}
	{Extension "BMW-R12.mdl"}
