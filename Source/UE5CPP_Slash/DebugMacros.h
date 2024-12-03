#pragma once
#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(),Location,25.0f,12,FColor::Red,true);
#define DRAW_SPHERE_SINGLEFRAME(Location) if (GetWorld()) DrawDebugSphere(GetWorld(),Location,25.0f,12,FColor::Red,false,-1.0f);
#define DRAW_LINE(StartLocation,EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true,-1.0f,0,10.f);
#define DRAW_LINE_SINGLEFRAME(StartLocation,EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false,-1.0f,0,10.f);
#define DRAW_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(), Location, FColor::Red, true);
#define DRAW_ARROW(StartLocation,EndLocation) if (GetWorld()) DrawDebugDirectionalArrow(GetWorld(), Location, EndLocation, 15.0f, FColor::Red, true);
#define DRAW_VECTOR(StartLocation,EndLocation) if (GetWorld()) \
{\
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true,-1.0f,0,10.f);\
	DrawDebugPoint(GetWorld(), EndLocation, FColor::Red, true);\
}
