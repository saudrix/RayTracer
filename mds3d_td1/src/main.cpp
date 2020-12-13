#include "viewer.h"
#include "stdio.h"

#include <filesystem/resolver.h>

void render(Scene* scene, ImageBlock* result, std::string outputName, bool* done)
{
    if(!scene)
        return;

    clock_t t = clock();

    const Camera *camera = scene->camera();
    //printf("camera:%p", camera);
    const Integrator* integrator = scene->integrator();
    integrator->preprocess(scene);

    float tanfovy2 = tan(camera->fovY()*0.5);
    Vector3f camX = camera->right() * tanfovy2 * camera->nearDist() * float(camera->vpWidth())/float(camera->vpHeight());
    Vector3f camY = -camera->up() * tanfovy2 * camera->nearDist();
    Vector3f camF = camera->direction() * camera->nearDist();

    /*Vector3f origin = camera->position();
    Vector3f imgOrigin = camera->position() + camF - camX - camY;
    float pxWidth = (float)(2 * camX.x()) / camera->vpWidth();
    float pxHeight = (float)(2 * camY.y()) / camera->vpHeight();
    for (int x = 0; x < camera->vpWidth(); x++)
    {
        for (int y = 0; y < camera->vpHeight(); y++)
        {
            //On a notre référence qui est en milieu de caméra (camF)
            float pixX = (x + 0.5) * pxWidth;
            float pixY = (y + 0.5) * pxHeight;

            Vector3f d = (imgOrigin + Vector3f(pixX, pixY, 0)).normalized();

            Ray ray = Ray(origin, d);
            Color3f color = integrator->Li(scene, ray);
            Vector2f pxPosition = Vector2f(pixX, pixY);
            result->put(pxPosition, color);
        }
    }*/

    float half_width = camera->vpWidth() * 0.5;
    float half_height = camera->vpHeight() * 0.5;

    for (size_t y = 0; y < camera->vpHeight(); y++) {
        for (size_t x = 0; x < camera->vpWidth(); x++) {

            float xVal = (x - half_width) / half_width;
            float yVal = (y - half_height) / half_height;

            Vector3f d = (xVal * camX + yVal * camY + camF).normalized();

            Ray ray = Ray(camera->position(), d);
            Color3f pixel = integrator->Li(scene, ray);

            result->put(Vector2f(float(x), float(y)), pixel);
        }
    }

    /// TODO:
    ///  1. iterate over the image pixels
    ///  2. generate a primary ray
    ///  3. call the integartor to compute the color along this ray
    ///  4. write this color in the result image

    t = clock() - t;
    std::cout << "Raytracing time : " << float(t)/CLOCKS_PER_SEC << "s"<<std::endl;

    *done = true;
}

int main(int argc, char *argv[])
{
    getFileResolver()->prepend(DATA_DIR);

    try {
        nanogui::init();
        Viewer *screen = new Viewer();;

        if (argc == 2) {
            /* load file from the command line */
            filesystem::path path(argv[1]);

            if(path.extension() == "scn") { // load scene file
                screen->loadScene(argv[1]);
            }else if(path.extension() == "exr") { // load OpenEXR image
                screen->loadImage(argv[1]);
            }
        }

        /* Enter the application main loop */
        nanogui::mainloop();

        delete screen;
        nanogui::shutdown();
    } catch (const std::exception &e) {
        cerr << "Fatal error: " << e.what() << endl;
        return -1;
    }
    return 0;
}
