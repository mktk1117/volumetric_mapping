#include "octomap_world/octomap_manager.h"
#include <nodelet/nodelet.h>

namespace volumetric_mapping_nodelet {

class VolumetricMappingNodelet : public nodelet::Nodelet
{
private:
  volumetric_mapping::OctomapManager *octomapManager;

public:
  VolumetricMappingNodelet() : Nodelet(), octomapManager(NULL)
  {
  }

  ~VolumetricMappingNodelet()
  {
    if(octomapManager)
    {
      delete octomapManager;
    }
  }

  virtual void onInit()
  {
    octomapManager = new volumetric_mapping::OctomapManager(getNodeHandle(), getPrivateNodeHandle());
  }
};

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(volumetric_mapping_nodelet::VolumetricMappingNodelet, nodelet::Nodelet)

}  // namespace volumetric_mapping_nodelet
