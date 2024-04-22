#include "showHandPublicDefs.h"
void ExFreeMemoryToNULL(_OUT_ PVOID* mem)
{
	free(*mem);
	*mem = NULL;
}