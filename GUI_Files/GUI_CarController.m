function varargout = GUI_CarController(varargin)
% GUI_CARCONTROLLER MATLAB code for GUI_CarController.fig
%      GUI_CARCONTROLLER, by itself, creates a new GUI_CARCONTROLLER or raises the existing
%      singleton*.
%
%      H = GUI_CARCONTROLLER returns the handle to a new GUI_CARCONTROLLER or the handle to
%      the existing singleton*.
%
%      GUI_CARCONTROLLER('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI_CARCONTROLLER.M with the given input arguments.
%
%      GUI_CARCONTROLLER('Property','Value',...) creates a new GUI_CARCONTROLLER or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_CarController_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_CarController_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI_CarController

% Last Modified by GUIDE v2.5 10-Feb-2020 02:57:42

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_CarController_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_CarController_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI_CarController is made visible.
function GUI_CarController_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI_CarController (see VARARGIN)

clc
%Start Simulink 
open_system('Arduino_Simulink_CarController')
% open_system('Arduino_Simulink_CarController/Scope')

%Enable Simulink To Recieve Commands From Matlab 
set_param('Arduino_Simulink_CarController','SimulationMode','external')
set_param('Arduino_Simulink_CarController','SimulationCommand','start')

%Initialize Two All Motor Pins To 0
set_param('Arduino_Simulink_CarController/FORWARD','Value','0');
set_param('Arduino_Simulink_CarController/REVERSE','Value','0');
set_param('Arduino_Simulink_CarController/RIGHT','Value','0');
set_param('Arduino_Simulink_CarController/LEFT','Value','0');


%creat a bluetooth object
%HC-05 channel default is 1
% b = Bluetooth('HC-05',1);
% fopen(b);
%write and read function
% fwrite(b,uint8(1));
%Bluetooth_Read=fgets(b);
%close and clear
%fclose(b);
%clear(b);

% Choose default command line output for GUI_CarController
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI_CarController wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_CarController_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in RightButton.
%Right Button
function RightButton_Callback(hObject, eventdata, handles)
% hObject    handle to RightButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('Arduino_Simulink_CarController/RIGHT','Value','1');
set_param('Arduino_Simulink_CarController/LEFT','Value','0');
% fwrite(b,uint8(1));

% --- Executes on button press in LeftButton.
%left Button
function LeftButton_Callback(hObject, eventdata, handles)
% hObject    handle to LeftButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('Arduino_Simulink_CarController/RIGHT','Value','0');
set_param('Arduino_Simulink_CarController/LEFT','Value','1');

% --- Executes on button press in FrontButton.
%Front button
function FrontButton_Callback(hObject, eventdata, handles)
% hObject    handle to FrontButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set_param('Arduino_Simulink_CarController/RIGHT','Value','0');
set_param('Arduino_Simulink_CarController/LEFT','Value','0');

% --- Executes on button press in StopButton.
%STOP button
function StopButton_Callback(hObject, eventdata, handles)
% hObject    handle to StopButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.ForwardButton,'Enable','on');
 set(handles.ReverseButton,'Enable','on');
set_param('Arduino_Simulink_CarController/FORWARD','Value','0');
set_param('Arduino_Simulink_CarController/REVERSE','Value','0');

% --- Executes on button press in ReverseButton.
%Reverse Button
function ReverseButton_Callback(hObject, eventdata, handles)
% hObject    handle to ReverseButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global reverse_button;
reverse_button = get(hObject,'Value');
if (reverse_button)
    set(handles.ForwardButton,'Enable','off');
end  
set_param('Arduino_Simulink_CarController/FORWARD','Value','0');
set_param('Arduino_Simulink_CarController/REVERSE','Value','1');
% Hint: get(hObject,'Value') returns toggle state of ReverseButton


% --- Executes on button press in ForwardButton.
%Forward Button
function ForwardButton_Callback(hObject, eventdata, handles)
% hObject    handle to ForwardButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global forward_button;
forward_button = get(hObject,'Value');
if (forward_button)
    set(handles.ReverseButton,'Enable','off');
end    
set_param('Arduino_Simulink_CarController/FORWARD','Value','1');
set_param('Arduino_Simulink_CarController/REVERSE','Value','0');
% Hint: get(hObject,'Value') returns toggle state of ForwardButton





% --- Executes on mouse press over figure background, over a disabled or
% --- inactive control, or over an axes background.
function figure1_WindowButtonUpFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on mouse press over figure background, over a disabled or
% --- inactive control, or over an axes background.
function figure1_WindowButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to figure1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over RightButton.
function RightButton_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to RightButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA


% --- If Enable == 'on', executes on mouse press in 5 pixel border.
% --- Otherwise, executes on mouse press in 5 pixel border or over LeftButton.
function LeftButton_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to LeftButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in ModeButton.
% Mode Button
function ModeButton_Callback(hObject, eventdata, handles)
% hObject    handle to ModeButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
global mode_button;
mode_button = get(hObject,'Value');
if (mode_button)
    set(handles.StopButton,'Enable','off');
    set(handles.ForwardButton,'Enable','off');
    set(handles.ReverseButton,'Enable','off');
    set(handles.FrontButton,'Enable','off');
    set(handles.RightButton,'Enable','off');
    set(handles.LeftButton,'Enable','off');
    set(handles.ModeText,'ForegroundColor','r');
    set(handles.ModeText,'String','AUTOMATIC LINE FOLLOWER MODE ACTIVATED');
else
    set(handles.StopButton,'Enable','on');
    set(handles.ForwardButton,'Enable','on');
    set(handles.ReverseButton,'Enable','on');
    set(handles.FrontButton,'Enable','on');
    set(handles.RightButton,'Enable','on');
    set(handles.LeftButton,'Enable','on');
    set(handles.ModeText,'ForegroundColor','b');
    set(handles.ModeText,'String','MANUAL MODE ACTIVATED');
end    
% Hint: get(hObject,'Value') returns toggle state of ModeButton
