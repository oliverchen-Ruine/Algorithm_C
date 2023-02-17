/********************************************************************************/
/*	@File Name		: NumberofRecentCalls.cpp
/*	@Created Date 	: 2022/05/07 09:43
/*	@Description	: 
/*
/*	@Version 		: V1.0
/*	@Copyright 		: Copyright(C) 2021-2022
/*	@Last Modified	: 2022/05/07 09:43
/*
/*	@Author 		: oliver_chen
/*	@Data   		: 2022/05/07 09:43
/*	@Remark			: @...@ 
/*
/*	@Reviser 		:
/*	@Data 			: 2022/05/07 09:43
/*	@Remark			: @...@
/********************************************************************************/
#include <iostream>

class RecentCounter {
    //******************************************************************************//
    //	@Author 		: oliver_chen
    //	@Created Date 	: 2022/05/07 09:43
    //
    //	@Class Name		: RecentCounter
    //	@Base Class 	:
    //	@Namespace 		: 
    //	@Description	: 
    //	@Remark			: @...@
    //******************************************************************************//
public:
    int left, right, request_list[10005];

    RecentCounter() {
        left = 0, right = 0;
    }

    int ping(int t) {
        /********************************************************************************/
        /*	@File Name		: NumberofRecentCalls.cpp
        /*	@Created Date 	: 2022/05/07 09:43
        /*	@Description	: 
        /*
        /*	@Version 		: V1.0
        /*	@Copyright 		: Copyright(C) 2021-2022
        /*	@Last Modified	: 2022/05/07 09:43
        /*
        /*	@Author 		: oliver_chen
        /*	@Data   		: 2022/05/07 09:43
        /*	@Remark			: @...@ 
        /*
        /*	@Reviser 		:
        /*	@Data 			: 2022/05/07 09:43
        /*	@Remark			: @...@
        /********************************************************************************/
        request_list[right++] = t;
        while (request_list[left] < t - 3000) {
            left++;
        }
        return right - left;
    }
};