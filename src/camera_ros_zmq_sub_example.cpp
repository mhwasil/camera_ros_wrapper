#include <sensor_data_transport_wrapper/zmq_pointcloud_transport.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/cloud_viewer.h>
int main(int argc, char *argv[])
{
    ZPT::ZMQPointCloudTransport zpt;
    zpt.init(ZPT::RECEIVER);
    usleep(100000);

    pcl::visualization::CloudViewer viewer("Cloud Viewer");
    pcl::PCLPointCloud2::Ptr pc(new pcl::PCLPointCloud2);
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
    while (true)
    {
        zpt.receive(pc);
        pcl::fromPCLPointCloud2(*pc, *cloud);
        viewer.showCloud(cloud);
        usleep(10000);
    }
    return 0;
}
