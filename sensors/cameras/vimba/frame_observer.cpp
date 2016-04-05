// This file is part of snark, a generic and flexible library for robotics research
// Copyright (c) 2016 The University of Sydney
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. Neither the name of the University of Sydney nor the
//    names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
// GRANTED BY THIS LICENSE.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
// HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
// BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <iostream>
#include <comma/application/verbose.h>
#include "snark/imaging/cv_mat/serialization.h"
#include "error.h"
#include "frame.h"
#include "frame_observer.h"

namespace snark { namespace vimba {

frame_observer::frame_observer( AVT::VmbAPI::CameraPtr camera
                              , std::unique_ptr< snark::cv_mat::serialization > serialization )
    : IFrameObserver( camera )
    , serialization_( std::move( serialization ))
{
    std::cerr << "Creating frame_observer" << std::endl;
}

void frame_observer::FrameReceived( const AVT::VmbAPI::FramePtr frame_ptr )
{
    frame frame( frame_ptr );

    frame.check_id();
    frame.check_status();

    // TODO: different image formats
    cv::Mat cv_mat( frame.get_height(), frame.get_width() * 1.5, CV_8UC1, frame.get_image_buffer() );

    serialization_->write( std::cout
                         , std::make_pair( boost::posix_time::microsec_clock::universal_time(), cv_mat ));

    m_pCamera->QueueFrame( frame_ptr );
}

} } // namespace snark { namespace vimba {
