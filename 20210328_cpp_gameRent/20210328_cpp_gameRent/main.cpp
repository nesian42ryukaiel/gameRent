//
//  main.cpp
//  20210328_cpp_gameRent
//
//  Created by 유기하 on 2021/03/17.
//

#include <iostream>
#include "gameRent.hpp"
#include "App.hpp"

//using namespace libsb;

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int argc, const char * argv[]) {
    App* session = App::getInstance(); // singleton을 써봄
    
    //session->routine();
    
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#ifdef __APPLE__
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Initialize OpenGL loader
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
    bool err = gl3wInit() != 0;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
    bool err = glewInit() != GLEW_OK;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
    bool err = gladLoadGL() == 0;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD2)
    bool err = gladLoadGL(glfwGetProcAddress) == 0; // glad2 recommend using the windowing library loader instead of the (optionally) bundled one.
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLBINDING2)
    bool err = false;
    glbinding::Binding::initialize();
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLBINDING3)
    bool err = false;
    glbinding::initialize([](const char* name) { return (glbinding::ProcAddress)glfwGetProcAddress(name); });
#else
    bool err = false; // If you use IMGUI_IMPL_OPENGL_LOADER_CUSTOM, your loader is likely to requires some form of initialization.
#endif
    if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state
    bool show_demo_window = false;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
//        {
//            static float f = 0.0f;
//            static int counter = 0;
//
//            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
//
//            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
//            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
//            ImGui::Checkbox("Another Window", &show_another_window);
//
//            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
//            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
//
//            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
//                counter++;
//            ImGui::SameLine();
//            ImGui::Text("counter = %d", counter);
//
//            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//            ImGui::End();
//        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }
        
        // 4. My take (Lucas Yew)
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 60, main_viewport->WorkPos.y + 60), ImGuiCond_FirstUseEver);
            ImGui::SetNextWindowSize(ImVec2(480, 600), ImGuiCond_FirstUseEver);
        
        {
            ImGui::Begin("Game Store Rent");
            
            if (ImGui::CollapsingHeader("Data Management"))
            {
                ImGui::Text("Load and save store data here.");
                if (ImGui::Button("Load##StoreData")) {
                    session->mFileRW->FileRW::loadCustomer(session->mCustomer);
                    session->mFileRW->FileRW::loadGame(session->mGame);
                }
                if (ImGui::Button("Save##StoreData")) {
                    session->mFileRW->FileRW::saveCustomer(session->mCustomer);
                    session->mFileRW->FileRW::saveGame(session->mGame);
                }
            }
            
            if (ImGui::CollapsingHeader("Rental Service"))
            {
                ImGui::Text("Rent and retrieve games here.");
                static int targetphone = 0; ImGui::InputInt("Phone##Rental", &targetphone, false);
                static int targetserial = 0; ImGui::InputInt("Serial##Rental", &targetserial, false); // false는 쁠마 버튼을 안 보이게 함
                
                {
                    if (ImGui::Button("Rent")) {
                        unsigned int parsedphone = (unsigned int)(targetphone);
                        unsigned int parsedserial = (unsigned int)(targetserial);
                        libsb::Node* phone = session->mCustomerManager->CustomerManager::findPhone(session->mCustomer, parsedphone);
                        libsb::Node* serial = session->mGameManager->GameManager::findSerial(session->mGame, parsedserial);
                        
                        if (phone != nullptr && serial != nullptr) {
                            if (serial->mIsOnRent == 0) {
                                serial->mIsOnRent = phone->mID;
                            } else {
                                // display as already rented
                            }
                        }
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("Retrieve")) {
                        unsigned int parsedphone = (unsigned int)(targetphone);
                        unsigned int parsedserial = (unsigned int)(targetserial);
                        libsb::Node* phone = session->mCustomerManager->CustomerManager::findPhone(session->mCustomer, parsedphone);
                        libsb::Node* serial = session->mGameManager->GameManager::findSerial(session->mGame, parsedserial);
                        
                        if (serial != nullptr) {
                            if (serial->mIsOnRent != 0) {
                                serial->mIsOnRent = 0;
                            } else {
                                // display as not rented
                            }
                            
                        }
                    }
                }
            }
            
            if (ImGui::CollapsingHeader("Customer Call"))
            {
                ImGui::Text("Enter phone number and name to manage.");
                static int newphone = 0; ImGui::InputInt("Phone##Customer", &newphone, false); // false는 쁠마 버튼을 안 보이게 함
                static char newname[64] = ""; ImGui::InputText("Name##Customer", newname, 64);
                
                {
                    
                    if (ImGui::Button("Signup##Customer")) {
                        unsigned int parsedphone = (unsigned int)(newphone); // static cast로 변경..할 예정
                        std::string parsedname(newname);
                        libsb::Node* phone = session->mCustomerManager->CustomerManager::findPhone(session->mCustomer, parsedphone);
                        libsb::Node* name = session->mCustomerManager->CustomerManager::findName(session->mCustomer, parsedname);
                        if (phone == nullptr) {
                            session->mCustomerManager->CustomerManager::signup(session->mCustomer, parsedphone, parsedname);
                        }
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("View##Customer")) {
                        unsigned int parsedphone = (unsigned int)(newphone);
                        std::string parsedname(newname);
                        libsb::Node* phone = session->mCustomerManager->CustomerManager::findPhone(session->mCustomer, parsedphone);
                        libsb::Node* name = session->mCustomerManager->CustomerManager::findName(session->mCustomer, parsedname);
                        if (phone != nullptr && phone == name) {
                            session->mCustomerManager->CustomerManager::viewIndividual(session->mCustomer, phone);
                        }
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("Unsign##Customer")) {
                        unsigned int parsedphone = (unsigned int)(newphone);
                        std::string parsedname(newname);
                        libsb::Node* phone = session->mCustomerManager->CustomerManager::findPhone(session->mCustomer, parsedphone);
                        libsb::Node* name = session->mCustomerManager->CustomerManager::findName(session->mCustomer, parsedname);
                        if (phone != nullptr && name != nullptr) {
                            session->mCustomerManager->CustomerManager::unsign(session->mCustomer, phone);
                        }
                    }
                }
                if (ImGui::Button("TestPrint")) { // move this around for testing list status
                    session->mCustomer->print(0);
                    session->mGame->print(0);
                }
            }
            
            if (ImGui::CollapsingHeader("Game Software"))
            {
                ImGui::Text("Enter phone number and name to manage.");
                static int newserial = 0; ImGui::InputInt("Serial##Game", &newserial, false); // false는 쁠마 버튼을 안 보이게 함
                static char newtitle[64] = ""; ImGui::InputText("Title##Game", newtitle, 64);
                
                {
                    
                    if (ImGui::Button("Stash##Game")) {
                        unsigned int parsedserial = (unsigned int)(newserial); // static cast로 변경..할 예정
                        std::string parsedtitle(newtitle);
                        libsb::Node* serial = session->mGameManager->GameManager::findSerial(session->mGame, parsedserial);
                        libsb::Node* title = session->mGameManager->GameManager::findTitle(session->mGame, parsedtitle);
                        if (serial == nullptr) {
                            session->mGameManager->GameManager::stash(session->mGame, parsedserial, parsedtitle);
                        }
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("View##Game")) {
                        unsigned int parsedserial = (unsigned int)(newserial); // static cast로 변경..할 예정
                        std::string parsedtitle(newtitle);
                        libsb::Node* serial = session->mGameManager->GameManager::findSerial(session->mGame, parsedserial);
                        libsb::Node* title = session->mGameManager->GameManager::findTitle(session->mGame, parsedtitle);
                        if (serial != nullptr && serial == title) {
                            session->mGameManager->GameManager::viewGame(session->mCustomer, serial);
                        }
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("Dispose##Game")) {
                        unsigned int parsedserial = (unsigned int)(newserial); // static cast로 변경..할 예정
                        std::string parsedtitle(newtitle);
                        libsb::Node* serial = session->mGameManager->GameManager::findSerial(session->mGame, parsedserial);
                        libsb::Node* title = session->mGameManager->GameManager::findTitle(session->mGame, parsedtitle);
                        if (serial != nullptr && title != nullptr) {
                            session->mGameManager->GameManager::dispose(session->mCustomer, serial);
                        }
                    }
                }
                if (ImGui::Button("TestPrint")) { // move this around for testing list status
                    session->mCustomer->print(0);
                    session->mGame->print(0);
                }
            }
            
            ImGui::Text("This is text for testing.");
            if (ImGui::CollapsingHeader("Help"))
            {
                ImGui::Text("ABOUT THIS DEMO:");
                ImGui::BulletText("Sections below are demonstrating many aspects of the library.");
                ImGui::BulletText("The \"Examples\" menu above leads to more demo contents.");
                ImGui::BulletText("The \"Tools\" menu above gives access to: About Box, Style Editor,\n"
                                  "and Metrics/Debugger (general purpose Dear ImGui debugging tool).");
                ImGui::Separator();

                ImGui::Text("PROGRAMMER GUIDE:");
                ImGui::BulletText("See the ShowDemoWindow() code in imgui_demo.cpp. <- you are here!");
                ImGui::BulletText("See comments in imgui.cpp.");
                ImGui::BulletText("See example applications in the examples/ folder.");
                ImGui::BulletText("Read the FAQ at http://www.dearimgui.org/faq/");
                ImGui::BulletText("Set 'io.ConfigFlags |= NavEnableKeyboard' for keyboard controls.");
                ImGui::BulletText("Set 'io.ConfigFlags |= NavEnableGamepad' for gamepad controls.");
                ImGui::Separator();

                ImGui::Text("USER GUIDE:");
                ImGui::ShowUserGuide();
            }
            ImGui::End();
        }
        
        // 5. customer list view
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 600, main_viewport->WorkPos.y + 60), ImGuiCond_FirstUseEver);
            ImGui::SetNextWindowSize(ImVec2(480, 270), ImGuiCond_FirstUseEver);
        {
            ImGui::Begin("Customer List");
            
            if (ImGui::BeginTable("table1", 2))
            {
                int custSize = (int)(session->mCustomer->size());
                libsb::Node* custIter = session->mCustomer->getHead();
                
                for (int row = 0; row < custSize; row++) {
                    ImGui::TableNextRow();
                    for (int column = 0; column < 2; column++) {
                        ImGui::TableSetColumnIndex(column);
                        if (column == 0) {
                            ImGui::Text("[%010u]", custIter->mID);
                        } else if (column == 1) {
                            ImGui::Text("%s", custIter->mName.c_str());
                        }
                    }
                    custIter = custIter->next;
                }
                ImGui::EndTable();
            }
            
            ImGui::End();
        }
        
        // 6. game list view
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x + 600, main_viewport->WorkPos.y + 390), ImGuiCond_FirstUseEver);
            ImGui::SetNextWindowSize(ImVec2(480, 270), ImGuiCond_FirstUseEver);
        {
            ImGui::Begin("Game List");
            
            if (ImGui::BeginTable("table2", 3))
            {
                int gameSize = (int)(session->mGame->size());
                libsb::Node* gameIter = session->mGame->getHead();
                
                for (int row = 0; row < gameSize; row++) {
                    ImGui::TableNextRow();
                    for (int column = 0; column < 3; column++) {
                        ImGui::TableSetColumnIndex(column);
                        if (column == 0) {
                            ImGui::Text("[%010u]", gameIter->mID);
                        } else if (column == 1) {
                            ImGui::Text("%s", gameIter->mName.c_str());
                        } else if (column == 2) {
                            if (gameIter->mIsOnRent != 0) {
                                ImGui::Text("rented by [%010u]", gameIter->mIsOnRent);
                            } else {
                                ImGui::Text("available");
                            }
                        }
                    }
                    gameIter = gameIter->next;
                }
                ImGui::EndTable();
            }
            
            ImGui::End();
        }
        
        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    
    return 0;
}
