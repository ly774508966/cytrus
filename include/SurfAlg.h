/* Carata Lucian, BSc Thesis Work
** Technical University of Iasi, 
** Faculty of Automatic Control and Computer Enigineering, 2009.
** 
** Author: Carata Lucian
** Project: Cytrus
** License notice:  GNU GPL
**
** in namespace cytrus::alg
** -----------------------------------------------------------------
** SurfAlg.h : The implementation for the SurfAlgorithm
**
*/

#ifndef _SURFALG_H_
#define _SURFALG_H_

#ifndef CYTRUSALGLIB_API
    #ifdef CYTRUSALGLIB_EXPORTS
        #define CYTRUSALGLIB_API __declspec(dllexport)
    #else
        #define CYTRUSALGLIB_API __declspec(dllimport)
    #endif
#endif

#include <vector>
#include "IImageConsumer.h"
#include "IImageSource.h"
#include "IPOIAlgorithm.h"
#include "ObjectPoiStorage.h"
#include "poi.h"

using namespace cytrus::cameraHAL;
using namespace cytrus::alg;

namespace cytrus{
    namespace alg{
        class CYTRUSALGLIB_API SurfAlg : public IPOIAlgorithm{
            private:
                volatile int _pWidth, _pHeight;
                volatile bool _isCustomPrelSize;
				static ObjectPoiStorage* _store;

            public:
                SurfAlg(IImageSource* imgSrc, POIAlgResult outputFunc, int index);
                virtual ~SurfAlg();

                virtual void processImage(unsigned long dwSize, unsigned char* pbData);

                virtual bool setProcessingSize(int newWidth, int newHeight);
                
                //Actions to take when the image from the source changes size
                virtual void onSourceSizeChange();
        };
    }
}

#endif
