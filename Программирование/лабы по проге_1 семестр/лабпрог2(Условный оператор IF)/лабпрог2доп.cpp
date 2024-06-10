#include <stdio.h>

int main()
{
	int min, gb, sumbaz, mindop = 0, gbdop = 0, allsum;
	printf("\n input min,gb");
	scanf("%d %d", &min, &gb);
	
	sumbaz = 200;
	allsum = 200;
	if (min > 50) {
		mindop = min - 50;
		allsum += mindop;
	}
	if (gb > 25) {
		gbdop = (gb - 25) * 25;
		allsum += gbdop;
	}
	
	printf("\n result: sumbaz=%d mindop=%d gbdop=%d allsum=%d", sumbaz, mindop, gbdop, allsum);
	return 0;
}
