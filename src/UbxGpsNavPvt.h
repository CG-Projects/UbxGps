#pragma once

#ifndef UBXGPSNAVPVT_H_
#define UBXGPSNAVPVT_H_

#include <UbxGps.h>

enum GNSSfixType
{
    no_fix = 0,
    dead_reckoning_only,
    fix_2D,
    fix_3D,
    GNSS_dead_reckoning_combined,
    time_only_fix,
};
enum FixStatusFlag
{

};

template <typename T>
class UbxGpsNavPvt : public UbxGps<T>
{
public:
    // Type   offs. Name           Unit     Description (scaling)
    //------------------------------------- HEADER ---------------------------
    // uint8_t  /*  */ mClass;     // -        Message Class
    // uint8_t  /*  */ mID;        // -        Message ID
    // uint16_t /*  */ Lenght;     // bytes    Lenght (in bytes) of Payload only
    //------------------------------------- START OF PAYLOAD ------------------
    uint32_t /* 0*/ iTOW;       // ms       GPS time of week of the navigation epoch.
                                //          See the description of iTOW for details
    uint16_t /* 4*/ year;       // y        Year UTC
    uint8_t /* 6*/ month;       // month    Month, range 1..12 UTC
    uint8_t /* 7*/ day;         // d        Day of month, range 1..31 UTC
    uint8_t /* 8*/ hour;        // h        Hour of day, range 0..23 UTC
    uint8_t /* 9*/ min;         // min      Minute of hour, range 0..59 UTC
    uint8_t /*10*/ sec;         // s        Seconds of minute, range 0..60 UTC
    uint8_t /*11*/ valid;       // -        Validity Flags
    uint32_t /*12*/ tAcc;       // ns       Time accuracy estimate UTC
    int32_t /*16*/ nano;        // ns       Fraction of second, range -1e9..1e9 UTC
    uint8_t /*20*/ fixType;     // -        GNSSfix Type, range 0..5
    uint8_t /*21*/ flags;       // -        Fix Status Flags
    uint8_t /*22*/ flags2;      // -        Additional flags
    uint8_t /*23*/ numSV;       // -        Number of satellites used in Nav Solution
    int32_t /*24*/ lon;         // deg      Longitude (1e-7)
    int32_t /*28*/ lat;         // deg      Latitude (1e-7)
    int32_t /*32*/ height;      // mm       Height above Ellipsoid
    int32_t /*36*/ hMSL;        // mm       Height above mean sea level
    uint32_t /*40*/ hAcc;       // mm       Horizontal Accuracy Estimate
    uint32_t /*44*/ vAcc;       // mm       Vertical Accuracy Estimate
    int32_t /*48*/ velN;        // mm/s     NED north velocity
    int32_t /*52*/ velE;        // mm/s     NED east velocity
    int32_t /*56*/ velD;        // mm/s     NED down velocity
    int32_t /*60*/ gSpeed;      // mm/s     Ground Speed (2-D)
    int32_t /*64*/ headMot;     // deg      Heading of motion 2-D (1e-5)
    uint32_t /*68*/ sAcc;       // mm/s     Speed Accuracy Estimate
    uint32_t /*72*/ headingAcc; // deg      Heading Accuracy Estimate (1e-5)
    uint16_t /*76*/ pDOP;       // -        Position DOP (0.01)
    uint16_t /*78*/ flags3;     // -        Additional Flags
    uint8_t /*80*/ reserved;    // -        Reserved
    int32_t /*84*/ headVeh;     // deg      Heading of Vehicle (2-D)
    int16_t /*88*/ magDec;      // deg      Magnetic declination
    uint16_t /*90*/ magAcc;     // deg      Magnetic declination accuracy
    //------------------------------------- FLAGS -----------------------------

    UbxGpsNavPvt(T &ser) : UbxGps<T>(ser)
    { 
        // Serial.println("UbxGPSNavPvt - INIT!!!!");                  
        this->setLength(92 /*Nr.of Bytes Payload*/);
    };
};

#endif
