{"bridge"
	{on "check_blast" overload
		{if volume "body"
			{if effector "dynamite"
				{set "blast" 1}
			else min_energy 7
				{set "blast" 1}
			}
		}
	}
	{on "criticalhit" overload}
}
