;SDL
{weatherfx rain
	{stage air "/fx/_bmp/flash/rain.ebm"
		{timer
			{mode play}
			{duration 0.8}
		}
		{Visibility
			{Linear
				{min 0.65 0.3}
				{max 0.2}
			}
		}
		{preTurn 160}
		{ScaleX 0.4 0.15}
		{ScaleY 0.08 0.02}
	}
	{stage water "/FX/_BMP/Flash/ripples_w.ebm"
		{Visibility
			{Linear
				{min 0.8 0.2}
				{max 0}
			}
		}
		{Scale
			{Linear
				{min 0.1 0.05}
				{max 0.4 0.2}
			}
		}
		{timer
			{mode play}
			{duration 0.5}
		}
	}
	{stage ground "/FX/_BMP/Flash/ripples_w.ebm"
		{Visibility
			{Linear
				{min 0.8 0.2}
				{max 0}
			}
		}
		{Scale
			{linear
				{min 0}
				{max 0.2 0.05}
			}
		}
		{timer
			{mode play}
			{duration 0.2}
		}
	}
}
