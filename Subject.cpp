#include "precompiled_header"
#include "Subject.h"
#include "stdafx.h"

Subject::~Subject() {
	putc(SUBJECT_DEATH, stdout);
	void Clear();
}

//void Subject::Attach(Observer*){
//	
//}
//
//void Subject::Detach(Observer*){
//
//}

void Subject::NotifyObservers(ObservedAction ObservedEvent){
	for (auto iter = observers.begin(); iter != observers.end(); iter++) {
		if (*iter = NULL) {
			fputc(ObservedEvent, stdout);
		}			
	}
}

void Subject::Clear(){
	for (auto iter = observers.begin(); iter != observers.end(); iter++)
		if(*iter)
			observers.pop_front();		
}
