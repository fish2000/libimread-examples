//
//  ofxIM.h
//  simple-libimread-example
//
//  Created by FI$H 2000 on 7/23/16.
//
//

#ifndef ofxIM_h
#define ofxIM_h

#include "ofImage.h"
#include <libimread/image.hh>

/// forward-declare buffer_t:
extern "C" {
    struct buffer_t;
}

/// forward-declare Halide::Type:
namespace Halide {
    struct Type;
}

namespace ofx {

    class ImageFactory;

    class Image : public im::Image {

        public:
            using factory_t = ofx::ImageFactory;
            using halotype_t = Halide::Type;

            Image() noexcept;
            Image(Image const&) noexcept;
            Image(Image&&) noexcept;
            Image(ofImage&&) noexcept;
            virtual ~Image();

            /// Image API
            virtual uint8_t* data() const;
            virtual uint8_t* data(int) const;
            halotype_t type() const;
            buffer_t* buffer_ptr() const;
            virtual int nbits() const override;
            virtual int nbytes() const override;
            virtual int ndims() const override;
            virtual int dim(int) const override;
            virtual int stride(int) const override;
            virtual int min(int) const override;
            virtual bool is_signed() const override;
            virtual bool is_floating_point() const override;
            inline off_t rowp_stride() const;
            virtual void* rowp(int) const override;

        private:
            ofImage backend;
    };

    class ImageFactory : public im::ImageFactory {

        public:
            using image_t = ofx::Image;
            using unique_t = std::unique_ptr<im::Image>;
            using shared_t = std::shared_ptr<im::Image>;

        public:
            ImageFactory() noexcept;
            virtual ~ImageFactory();

        protected:
            virtual unique_t create(int nbits,
                                    int xHEIGHT, int xWIDTH, int xDEPTH,
                                    int d3, int d4) override;


    };


}


#endif /* ofxIM_h */
