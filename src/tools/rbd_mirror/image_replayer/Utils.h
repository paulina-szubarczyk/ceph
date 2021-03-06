// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab

#ifndef RBD_MIRROR_IMAGE_REPLAYER_UTILS_H
#define RBD_MIRROR_IMAGE_REPLAYER_UTILS_H

#include "include/int_types.h"
#include "include/rados/librados.hpp"
#include "include/rbd/librbd.hpp"
#include "librbd/internal.h"
#include <string>

namespace rbd {
namespace mirror {
namespace image_replayer {
namespace utils {

// TODO: free-functions used for mocking until create/clone
//       converted to async state machines
template <typename I>
int clone_image(I *p_imctx, librados::IoCtx& c_ioctx, const char *c_name,
                librbd::ImageOptions& c_opts,
                const std::string &non_primary_global_image_id,
                const std::string &primary_mirror_uuid) {
  return librbd::clone(p_imctx, c_ioctx, c_name, c_opts,
                       non_primary_global_image_id, primary_mirror_uuid);
}

} // namespace utils
} // namespace image_replayer
} // namespace mirror
} // namespace rbd

#endif // RBD_MIRROR_IMAGE_REPLAYER_UTILS_H

